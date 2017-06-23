#include "html_form.hpp"

#include <string>

using namespace std;

namespace html {

HTMLForm::HTMLForm(void)
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
	m_html_form = "<form";
	if (!m_form_action.empty())
	{
		 m_html_form += " action \"" + m_html_form + "\"";
	}
	m_html_form += ">";
	/* Iterate over the form input objects */
	m_html_form += "<\form>";
}

string HTMLForm::get_form(void)
{
	return m_html_form;
}


}

