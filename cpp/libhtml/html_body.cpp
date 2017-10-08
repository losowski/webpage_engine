#include "html_body.hpp"

#include <string>
#include <boost/foreach.hpp>

using namespace std;

namespace html {

HTMLBody::HTMLBody(void): m_html_title("Test Page")
{
}

HTMLBody::~HTMLBody(void)
{
}

void HTMLBody::create_body(void)
{
	/* Run the creation algorithms */
	m_html_title.create_title();
	/* Generate the actual page */
	m_html_body.clear();
	m_html_body += "Content-type: text/html\n\n";
	m_html_body += "<html>\n";
	/* Header */
	m_html_body += "<head>\n";
	/* title */
	m_html_body += m_html_title.get_title();
	/* script */
	/* style */
	/* meta */
	BOOST_FOREACH(HTMLHeaderPtr headerinput, m_html_header_content)
	{
		headerinput->create_header();
		m_html_body += headerinput->get_header();
	}
	m_html_body += "</head>\n";
	/* body */
	m_html_body += "<body>\n";
	/* ALL body components are to be made using the same base class:
	 -	div
	 -	form
	 -	text
	 -	hyperlink
	 -	image
	*/
	BOOST_FOREACH(HTMLFormPtr htmlcontent, m_html_content)
	{
		htmlcontent->create_form();
		m_html_body += htmlcontent->get_form();
	}
	m_html_body += "</body>\n";
	/* End of HTML */
	m_html_body += "</html>\n";
}

string HTMLBody::get_page(void)
{
	return m_html_body;
}


void HTMLBody::add_title(HTMLTitle & title)
{
	m_html_title = title;
}


HTMLTitle & HTMLBody::get_title(void)
{
	return m_html_title;
}

void HTMLBody::add_script(const string & url)
{
	HTMLHeaderPtr script ( new header::HTMLHeaderScript(url));
	m_html_header_content.push_back(script);
}

void HTMLBody::add_style(const string & url)
{
	HTMLHeaderPtr style ( new header::HTMLHeaderStyle(url));
	m_html_header_content.push_back(style);
}

/* Only allowed once */
void HTMLBody::add_meta_data(const header::MetaType & type, const string & content)
{
	HTMLHeaderPtr meta ( new header::HTMLHeaderMeta(type, content));
	m_html_header_content.push_back(meta);
}


HTMLFormPtr HTMLBody::add_form(const string & name, const string & action)
{
	HTMLFormPtr content_item (new HTMLForm(name, action));
	m_html_content.push_back(content_item);
	return content_item;
}

}
