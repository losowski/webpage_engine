#ifndef HTML_FORM_INPUT_HPP
#define HTML_FORM_INPUT_HPP

#include <string>

using namespace std;

namespace html {
namespace form {
class HTMLFormInput {
	public:
		/* Constuctor must be virtual if a function is virtual */
		HTMLFormInput();
		HTMLFormInput(const string type, const string & field_name, const string & label, const string & value);
		virtual ~HTMLFormInput();
	public:
		virtual void create_form_input(void);
		string get_form_input(void);
	public:
		const string			m_type;
	protected:
		string					m_field_name;
		string					m_label;
		string					m_value;
		string					m_html_form_input;
};
}
}
#endif //HTML_FORM_INPUT_HPP
