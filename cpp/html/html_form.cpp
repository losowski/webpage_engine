#include "html_form.hpp"
#include "form/html_form_input_text.hpp"

#include <string>

using namespace std;

namespace html {

HTMLForm::HTMLForm(const string & name, const string & action): m_html_form_name(name), m_html_form_action(action)
{
}

HTMLForm::~HTMLForm(void)
{
}

void HTMLForm::create_form(void)
{
	//Call the create object function on each element - might need to be a static function
	//for_each (m_html_form_input.begin(), m_html_form_input;.end(), create_form_input);
	/* Create the form */
	m_html_form = "<form name=\"" + m_html_form_name +  "\"";
	if (!m_html_form_action.empty())
	{
		 m_html_form += " action=\"" + m_html_form_action + "\"";
	}
	m_html_form += ">";
	/* Iterate over the form input objects */
	m_html_form += "</form>";
}

string HTMLForm::get_form(void)
{
	return m_html_form;
}

void HTMLForm::add_text_input(const string & field_name, const string & label, const string & value)
{
	HTMLFormInputPtr input_field ( new form::HTMLFormInputText(field_name, label, value));
	m_html_form_input.push_back(input_field);	
}

}

