#include "html_form_input_radio.hpp"

#include <string>

using namespace std;

namespace html {
namespace form {

HTMLFormInputRadio::HTMLFormInputRadio(const string & field_name, const string & label, const string & value):
	HTMLFormInput ("radio",field_name, label, value)
{
}

HTMLFormInputRadio::~HTMLFormInputRadio()
{
}

void HTMLFormInputRadio::create_form_input(void)
{
	m_html_form_input = "<br>" + m_label + "<br>\n";
	m_html_form_input += "<input type=\"" + m_type + "\" name=\"" + m_field_name + "\" value=\"" + m_value + "\">";
	m_html_form_input += "</input>\n";
}

}
}

