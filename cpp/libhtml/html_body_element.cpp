#include "html_body_element.hpp"

#include <boost/foreach.hpp>

using namespace std;

namespace html {

HTMLBodyElement::HTMLBodyElement(void)
{
}

HTMLBodyElement::HTMLBodyElement(const string & type, const string & name):
	m_type(type),
	m_name(name)
{
}

HTMLBodyElement::~HTMLBodyElement(void)
{
}

void HTMLBodyElement::create_html(void)
{
	m_html = "<" + m_type + " name=\"" + m_name + "\">\n";
	BOOST_FOREACH(HTMLBodyBasePtr bodyContent, m_html_body_content)
	{
		bodyContent->create_html();
		m_html += bodyContent->get_html();
	}
	m_html = "\n</" + m_type + ">\n";
}

HTMLFormPtr HTMLBodyElement::add_form(const string & name, const string & action)
{
	//TODO: HTMLForm is meant to derive off HTMLBase so that it can 
	HTMLBodyBasePtr content_item (new HTMLForm(name, action));
	m_html_body_content.push_back(content_item);
	return content_item;
}

}
