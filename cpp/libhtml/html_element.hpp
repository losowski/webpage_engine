#ifndef HTML_ELEMENT_HPP
#define HTML_ELEMENT_HPP

#include "form/html_form_input.hpp"
#include "form/html_form_input_menu.hpp"

#include <string>
#include <list>
#include <boost/shared_ptr.hpp>

using namespace std;

namespace html {

//Forward Definition
class HTMLElement;

class HTMLElement {
	public:
		HTMLElement(void);
		~HTMLElement(void);
	public:
		virtual void create_element(void) = 0;
		string get_element(void);
	public:
		//helper functions
		void create_sub_elements(void);
	private:
		list< HTMLElement >					m_html_element_list;
		string								m_html_element;
};
}
#endif //HTML_ELEMENT_HPP
