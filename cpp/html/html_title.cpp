#include "html_title.hpp"

#include <string>

using namespace std;

namespace html {

HTMLTitle::HTMLTitle(const string & title): m_title(title)
{
}

HTMLTitle::~HTMLTitle(void)
{
}

void HTMLTitle::create_title(void)
{
	m_html_title = "<head>" + m_title + "</head>\n";
}

string HTMLTitle::get_title(void)
{
	return m_html_title;
}

void HTMLTitle::set_title(const string & title)
{
	m_title = title;
}

}

