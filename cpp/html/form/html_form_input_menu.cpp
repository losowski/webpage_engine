#include "html_form_input_text.hpp"

#include <string>

using namespace std;

namespace html {
namespace form {

HTMLFormInputMenu::HTMLFormInputMenu(const string & field_name, const string & label, const string & value):
	HTMLFormInput ("text",field_name, label, value),
	m_size_to_display(5),
	m_multiple_selections(false)
{
}

HTMLFormInputMenu::~HTMLFormInputMenu()
{
}

void HTMLFormInputMenu::create_form_input(void)
{
	m_html_form_input = "<br>" + m_label + "<br>\n";
	m_html_form_input += "<select \" name=\"" + m_field_name + "\" "
	if (m_multiple_selections == true)
	{
		m_html_form_input += "multiple";
	}
	else
	{
		m_html_form_input += "multiple";
	}
	m_html_form_input += " size=\"" + to_string(m_size_to_display) + "\">\n";
	BOOST_FOREACH(HTMLFormInputMenuSelection selection, m_selections)
	{
		selection->create_form_input();
		m_html_form += selection->get_form_input();
	}W
	m_html_form_input += "</select>\n";
}

void HTMLFormInputMenu::add_menu_selection(const string & label, const string & value, bool selected = false)
{
	HTMLFormInputMenuSelectionPtr input_field ( new form::HTMLFormInputMenuSelectionPtr(label, value, selected));
	m_selections.push_back(input_field);
}

}
}

