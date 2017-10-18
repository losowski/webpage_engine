#ifndef HTML_ELEMENT_FACTORY_HPP
#define HTML_ELEMENT_FACTORY_HPP

#include "html_element_factory_base.hpp"

#include "html_body_element.hpp"
#include "html_form.hpp"
#include "html_div.hpp"
#include "html_span.hpp"
#include "html_h1.hpp"


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
		/* generic Formatting */
		static HTMLBodyElementPtr add_div(HTMLBodyElementPtr element, const string & name, const string & text = "");
		static HTMLBodyElementPtr add_span(HTMLBodyElementPtr element, const string & name, const string & text = "");
		static HTMLBodyElementPtr add_h1(HTMLBodyElementPtr element, const string & name, const string & text = "");

};

}
#endif //HTML_ELEMENT_FACTORY_HPP
