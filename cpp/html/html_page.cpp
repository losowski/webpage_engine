#include "html_page.hpp"

#include <string>

using namespace std;

namespace html {

HTMLPage::HTMLPage(void): m_html_title("Test Page")
{
}

HTMLPage::HTMLPage(const string & title): m_html_title(title)
{
}

HTMLPage::~HTMLPage(void)
{
}

void HTMLPage::create_page(void)
{
	/* Run the creation algorithms */
	m_html_title.create_title();
	/* Generate the actual page */
	m_html_page.clear();
	m_html_page += "Content-type: text/html\n\n";
	m_html_page += "<html>\n";
	/* Header */
	m_html_page += "<head>\n";
	/* title */
	m_html_page += m_html_title.get_title();
	/* script */
	/* style */
	/* meta */
	m_html_page += "</head>\n";
	/* body */
	m_html_page += "<body>\n";
	/* ALL body components are to be made using the same base class:
	 -	div
	 -	form
	 -	text
	 -	hyperlink
	 -	image 
	*/
	m_html_page += "</body>\n";
	/* End of HTML */
	m_html_page += "</html>\n";
}

string HTMLPage::get_page(void)
{
	return m_html_page;
}


void HTMLPage::add_title(HTMLTitle & title)
{
	m_html_title = title;
}

HTMLTitle & HTMLPage::get_title(void)
{
	return m_html_title;
}

HTMLFormPtr HTMLPage::add_form(const string & name, const string & action)
{
	HTMLFormPtr content_item (new HTMLForm(name, action));
	m_html_content.push_back(content_item);
	return content_item;
}

