#include "html_element_factory.hpp"


using namespace std;

namespace html {

HTMLElementFactory::HTMLElementFactory(void)
{
}

HTMLElementFactory::~HTMLElementFactory(void)
{
}

/* Form */
HTMLFormPtr HTMLElementFactory::add_form(HTMLBodyElementPtr element, const string & name, const string & action)
{
	HTMLFormPtr content_item (new HTMLForm(name, action));
	element->add_element(content_item);
	return content_item;
}


HTMLBodyElementPtr HTMLElementFactory::add_div(HTMLBodyElementPtr element, const string & name, const string & text)
{
	HTMLBodyElementPtr content_item (new HTMLDiv(name, text));
	element->add_element(content_item);
	return content_item;
}

HTMLBodyElementPtr HTMLElementFactory::add_span(HTMLBodyElementPtr element, const string & name, const string & text)
{
	HTMLBodyElementPtr content_item (new HTMLSpan(name, text));
	element->add_element(content_item);
	return content_item;
}

HTMLBodyElementPtr HTMLElementFactory::add_h1(HTMLBodyElementPtr element, const string & name, const string & text)
{
	HTMLBodyElementPtr content_item (new HTMLH1(name, text));
	element->add_element(content_item);
	return content_item;
}


}
