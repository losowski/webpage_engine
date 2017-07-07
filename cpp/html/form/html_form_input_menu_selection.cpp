#include "html_form_input.hpp"

using namespace std;

namespace html {
namespace form {

HTMLFormInputMenuSelectionMenuSelection::HTMLFormInputMenuSelectionMenuSelection(const string & label, const string & value, bool selected = false):
	HTMLFormInput ("option",label, label, value),
	m_selected(selected)
{
}

HTMLFormInputMenuSelection::~HTMLFormInputMenuSelection()
{
}

string HTMLFormInputMenuSelection::create_form_input(void)
{
	m_html_form_input = "<" + m_type;
	if (m_selected == true)
	{
		m_html_form_input += " selected";
	}
	m_html_form_input += " value=\"" + m_value + "\">" + m_label + "</" + m_type + ">";
}

string HTMLFormInputMenuSelection::get_form_input(void)
{
	return m_html_form_input;
}

}
}
