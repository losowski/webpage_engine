#ifndef HTML_FORM_INPUT_HPP
#define HTML_FORM_INPUT_HPP

#include "html_form_input.hpp"

#include <string>
#include <list>

using namespace std;

namespace html {
namespace form {
class HTMLFormInput {
	public:
		HTMLFormInput(void);
		~HTMLFormInput(void);
	public:
		void create_form_input(void);
		string get_form_input(void);
	private:
		const string			m_type;
		string					m_field_name;
		string					m_label;
		string					m_value;
		string					m_html_form;
};
}
}
#endif //HTML_FORM_INPUT_HPP
