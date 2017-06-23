#ifndef HTML_FORM_HPP
#define HTML_FORM_HPP

//#include "html_form_input.hpp"

#include <string>
#include <list>

using namespace std;

namespace html {
class HTMLForm {
	public:
		HTMLForm(void);
		~HTMLForm(void);
	public:
		void create_form(void);
		//HTMLFormInput * add_	
		string get_form(void);
	private:
//		list<HTMLFormInput>		m_html_form_input;
		string					m_form_action;
		string					m_html_form;
};
}
#endif //HTML_FORM_HPP