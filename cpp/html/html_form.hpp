#ifndef HTML_FORM_HPP
#define HTML_FORM_HPP

#include "form/html_form_input.hpp"

#include <string>
#include <list>
#include <boost/shared_ptr.hpp>

using namespace std;

namespace html {

typedef boost::shared_ptr<form::HTMLFormInput> HTMLFormInputPtr;

class HTMLForm {
	public:
		HTMLForm(const string & name, const string & action);
		~HTMLForm(void);
	public:
		void create_form(void);
		void add_text_input(const string & field_name, const string & label, const string & value = "");
		string get_form(void);
	private:
		list< HTMLFormInputPtr >			m_html_form_input;
		string								m_html_form;
		string								m_html_form_name;
		string								m_html_form_action;
};
}
#endif //HTML_FORM_HPP
