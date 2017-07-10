#include "html_form.hpp"
#include "form/html_form_input_text.hpp"
#include "form/html_form_input_radio.hpp"
#include "form/html_form_input_menu.hpp"

#include <string>
#include <boost/foreach.hpp>

using namespace std;

namespace html {


const HTMLFormInputMethod HTMLForm::HTML_FORM_GET("GET");
const HTMLFormInputMethod HTMLForm::HTML_FORM_POST("POST");


HTMLForm::HTMLForm(const string & name, const string & action): m_submit_method(HTMLForm::HTML_FORM_POST), m_submit_button_name("Submit"), m_reset_button(false), m_html_form_name(name), m_html_form_action(action)
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
	m_html_form += " method=\"" +  m_submit_method +  "\">\n";
	/* Iterate over the form input objects */
	BOOST_FOREACH(HTMLFormInputPtr forminput, m_html_form_input)
	{
		forminput->create_form_input();
		m_html_form += forminput->get_form_input();
	}
	m_html_form += "<input type=\"submit\" value=\"" + m_submit_button_name + "\">";
	if (m_reset_button == true)
	{
		m_html_form += "<input type=\"reset\">";
	}
	m_html_form += "</form>";
}

string HTMLForm::get_form(void)
{
	return m_html_form;
}

void HTMLForm::set_method(const HTMLFormInputMethod & method)
{
}

//Text Type Inputs
void HTMLForm::add_text_input(const string & field_name, const string & label, const string & value)
{
	HTMLFormInputPtr input_field ( new form::HTMLFormInputText(field_name, label, value));
	m_html_form_input.push_back(input_field);	
}

HTMLFormInputMenuPtr HTMLForm::add_menu_input(const string & field_name, const string & label)
{
	HTMLFormInputMenuPtr input_field ( new HTMLFormInputMenuPtr(field_name, label));
	m_html_form_input.push_back(input_field);
	return 	 input_field;
}

//Check Box Type Inputs
void HTMLForm::add_radio_input(const string & field_name, const string & label)
{
	HTMLFormInputPtr input_field ( new form::HTMLFormInputRadio(field_name, label));
	m_html_form_input.push_back(input_field);	
}

//Button Type Inputs
void HTMLForm::set_submit_name(const string & button_name)
{
	m_submit_button_name = button_name;
}

void HTMLForm::add_reset_input(void)
{
	m_reset_button = true;
}

}

