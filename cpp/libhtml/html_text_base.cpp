#include "html_text_base.hpp"

#include <boost/foreach.hpp>

using namespace std;

namespace html {

HTMLTextBase::HTMLTextBase(const string & type, const string & name, const string & text):
	HTMLBodyElement(type, name),
	m_text(text)
	
{
}

HTMLTextBase::~HTMLTextBase(void)
{
}

void HTMLTextBase::create_html(void)
{
	m_html = "<" + m_type + " class=\"" + m_name + "\">\n";
	create_child_html();
	m_html += "</" + m_type + ">\n";
}

void HTMLTextBase::create_child_html(void)
{
	if (m_text.empty() == true)
	{
		BOOST_FOREACH(HTMLBodyBasePtr bodyContent, m_html_body_content)
		{
			bodyContent->create_html();
			m_html += bodyContent->get_html();
		}
	}
	else
	{
		m_html += m_text;
	}
}

}
