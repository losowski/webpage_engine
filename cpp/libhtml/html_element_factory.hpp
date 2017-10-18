#ifndef HTML_ELEMENT_FACTORY_HPP
#define HTML_ELEMENT_FACTORY_HPP

#include "html_element_factory_base.hpp"

#include "html_body_element.hpp"
#include "html_form.hpp"

using namespace std;

namespace html {

class HTMLElementFactory : public html::HTMLElementFactoryBase
{
	public:
		HTMLElementFactory(void);
		~HTMLElementFactory(void);
	public:
		/* Form */
		static HTMLFormPtr add_form(HTMLBodyElementPtr element, const string & name, const string & action);

};

}
#endif //HTML_ELEMENT_FACTORY_HPP
