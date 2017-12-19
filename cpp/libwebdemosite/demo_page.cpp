#include "demo_page.hpp"

//Libpxx
#include <pqxx/cursor>
#include <pqxx/transaction>
#include <pqxx/result>

using namespace std;
using namespace html;
using namespace cgicc;

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
	addCSS("demo-layout");
	//Scripts
	//HTML
	HTMLBodyBasePtr demo = m_page.add_div("demo-layout");
	//MENU
	HTMLFormPtr df = HTMLElementFactory::add_form(demo, "demoform", "demopage.cgi");
	df->add_text_input("id", "id", m_id);
	df->add_text_input("forename", "Forename", m_forename);
	df->add_text_input("happiness", "Happiness Level", m_happiness);
	df->add_text_input("creation_date", "Creation Date", m_created_date);
	df->set_submit_name("Enter");
}

void DemoPage::actionDataCGI(void)
{
	/*
		Code design
		1) Get the form in the class cgicc::FormEntry
			cgicc::form_iterator it = m_cgi->getElement("libwebsite.cgi");
		2) For each field in the named form, get the data using "getValue"
	*/
	//Get Form
	m_cgi->getElement("demoform");
	// -- Iterators
	cgicc::form_iterator itid = m_cgi->getElement("id");
	cgicc::form_iterator itforename = m_cgi->getElement("forename");
	cgicc::form_iterator ithappiness = m_cgi->getElement("happiness");
	cgicc::form_iterator itcreation_date = m_cgi->getElement("creation_date");
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
		m_created_date = itcreation_date->getValue();
	}
	//Get QueryString
	m_id = getCGIEnvironment("id");
}


void DemoPage::actionDataUpdateSQL (pqxx::work & txn, const string & key)
{
	pqxx::result res = txn.exec("demo_schema.pUpdContact(" + txn.quote(m_id) + ","  + txn.quote(m_forename) + ","  + txn.quote(m_happiness) +","  + txn.quote(m_created_date) +")");
}

void DemoPage::actionDataSelectSQL (pqxx::work & txn)
{
	//Run Query
	pqxx::result res = txn.exec("demo_schema.pSelContact(" + txn.quote(m_id) + ")");
	//Process result
	/*
	for (auto row: res) {
		m_forename.assign(row["forename"].c_str());
		m_happiness.assign(row["happiness"].c_str());
		m_created_date.assign(row["created_date"].c_str());
	}
	*/
}



}
