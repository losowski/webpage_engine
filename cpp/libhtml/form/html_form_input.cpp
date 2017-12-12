#include "html_form_input.hpp"

using namespace std;

namespace html {
namespace form {

HTMLFormInput::HTMLFormInput()
{
}

HTMLFormInput::HTMLFormInput(const string type, const string & field_name, const string & label, const string & value):
	m_type(type),
	m_field_name(field_name),
	m_label(label),
	m_value(value)
{
}

HTMLFormInput::~HTMLFormInput()
{
}

//Create Label
void HTMLFormInput::create_label(void)
{
	m_html_form_input = "<div class=\"" + m_field_name+ "\">" + m_label + "</div>\n";
}
//Get the form input
string HTMLFormInput::get_form_input(void)
{
	return m_html_form_input;
}




}
}

