#include "html_element.hpp"
#include <string>
#include <boost/foreach.hpp>

using namespace std;

namespace html {


HTMLForm::HTMLForm(void)
{
}

HTMLForm::~HTMLForm(void)
{
}


void HTMLForm::create_sub_elements(void)
{
	/* Iterate over the form input objects */
	BOOST_FOREACH(HTMLFormInputPtr forminput, m_html_element_list)
	{
		forminput->create_form_input();
		m_html_element += forminput->get_form_input();
	}
}

string HTMLForm::get_element(void)
{
	return m_html_element;
}


}

