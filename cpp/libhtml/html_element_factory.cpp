#include "html_element_factory.hpp"

#include "html_body_element.hpp"
#include "html_form.hpp"

using namespace std;

namespace html {

HTMLElementFactory::HTMLElementFactory(void):
	HTMLElementFactoryBase(void)
{
}

HTMLElementFactory::~HTMLElementFactory(void)
{
}

/* Form */
static HTMLFormPtr HTMLElementFactory::add_form(HTMLBodyElementPtr element, const string & name, const string & action)
{
	HTMLFormPtr content_item (new HTMLForm(name, action));
	element.add_element(content_item);
	return content_item;
}


}
