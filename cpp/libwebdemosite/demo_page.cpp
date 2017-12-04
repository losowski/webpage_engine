#include "demo_page.hpp"

using namespace std;
using namespace html;

namespace web {

DemoPage::DemoPage(const string & title):
		web::WebPageBase ( title )
{

}

DemoPage::~DemoPage(void)
{
}
//Public
void DemoPage::buildMainMenu(void)
{
	//Style
	addCSS("default-layout");
	//Scripts
	//HTML
	HTMLBodyBasePtr demo = m_page.add_div("demo-layout");
	//MENU
	HTMLFormPtr df = HTMLElementFactory::add_form(demo, "demoform", "libdemosite.cgi");
	df->add_text_input("id", "id", m_id);
	df->add_text_input("forename", "forename", m_forename);
	df->add_text_input("happiness", "happiness", m_happiness);
	df->add_text_input("creation_date", "creation_date", m_creation_date);
	df->set_submit_name("Enter");
}

void DemoPage::actionDataCGI(void)
{
	// -- Iterators
	const_form_iterator itid = m_cgi->getElement("id");
	const_form_iterator itforename = m_cgi->getElement("forename");
	const_form_iterator ithappiness = m_cgi->getElement("happiness");
	const_form_iterator itcreation_date = m_cgi->getElement("creation_date");
	// -- Setting the values
	if (itid != m_cgi->getElements().end() && itid->getValue().empty() == false)
	{
		m_id = itid->getValue();
	}
	if (itforename != m_cgi->getElements().end() && itforename->getValue().empty() == false)
	{
		m_forename = itforename->getValue();
	}
	if (ithappiness != m_cgi->getElements().end() && ithappiness->getValue().empty() == false)
	{
		m_happiness = ithappiness->getValue();
	}
	if (itcreation_date != m_cgi->getElements().end() && itcreation_date->getValue().empty() == false)
	{
		m_creation_date = itcreation_date->getValue();
	}
}

void DemoPage::actionDataSQL (void)
{
}

}
