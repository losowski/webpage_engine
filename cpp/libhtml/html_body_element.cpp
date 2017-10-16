#include "html_body_element.hpp"

using namespace std;

namespace html {

HTMLBodyElement::HTMLBodyElement(void)
{
}

HTMLBodyElement::HTMLBodyElement(const string & type, const string & name):
	HTMLBodyBase(type, name)
{
}

HTMLBodyElement::~HTMLBodyElement(void)
{
}


HTMLFormPtr HTMLBodyElement::add_form(const string & name, const string & action)
{
	HTMLBodyBasePtr content_item (new html::HTMLForm(name, action));
	m_html_body_content.push_back(content_item);
	return content_item;
}

}
