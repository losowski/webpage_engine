#ifndef HTML_FORM_INPUT_HPP
#define HTML_FORM_INPUT_HPP

#include <string>
#include <list>

using namespace std;

namespace html {
namespace form {
class HTMLFormInput {
	public:
		/* Constuctor must be virtual if a function is virtual */
		virtual HTMLFormInput();
		~HTMLFormInput();
	public:
		virtual void create_form_input(void);
		string get_form_input(void);
	protected:
		const string			m_type;
		string					m_field_name;
		string					m_label;
		string					m_value;
	private:
		string					m_html_form_input;
};
}
}
#endif //HTML_FORM_INPUT_HPP
