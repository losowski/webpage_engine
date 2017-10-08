#include "html_body.hpp"

#include <boost/foreach.hpp>

using namespace std;

namespace html {

HTMLBody::HTMLBody(void)
{
}

HTMLBody::~HTMLBody(void)
{
}

void HTMLBody::create_body(void)
{
	/* body */
	m_html += "<body>\n";
	/* ALL body components are to be made using the same base class:
	 -	div
	 -	form
	 -	text
	 -	hyperlink
	 -	image 
	*/
	BOOST_FOREACH(HTMLBasePtr bodyContent, m_html_body_content)
	{
		bodyContent->create_html();
		m_html += bodyContent->get_html();
	}
	m_html += "</body>\n";
}

HTMLFormPtr HTMLBody::add_form(const string & name, const string & action)
{
	//TODO: HTMLForm is meant to derive off HTMLBase so that it can 
	HTMLFormPtr content_item (new HTMLForm(name, action));
	m_html_body_content.push_back(content_item);
	return content_item;
}

}
