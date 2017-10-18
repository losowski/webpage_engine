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
HTMLFormPtr HTMLElementFactory::add_form(HTMLBodyBasePtr element, const string & name, const string & action)
{
	HTMLFormPtr content_item (new HTMLForm(name, action));
	element->add_element(content_item);
	return content_item;
}


HTMLBodyBasePtr HTMLElementFactory::add_div(HTMLBodyBasePtr element, const string & name, const string & text)
{
	HTMLBodyElementPtr content_item (new HTMLDiv(name, text));
	element->add_element(content_item);
	return content_item;
}

HTMLBodyBasePtr HTMLElementFactory::add_span(HTMLBodyBasePtr element, const string & name, const string & text)
{
	HTMLBodyElementPtr content_item (new HTMLSpan(name, text));
	element->add_element(content_item);
	return content_item;
}

HTMLBodyBasePtr HTMLElementFactory::add_h1(HTMLBodyBasePtr element, const string & name, const string & text)
{
	HTMLBodyElementPtr content_item (new HTMLH1(name, text));
	element->add_element(content_item);
	return content_item;
}


}
