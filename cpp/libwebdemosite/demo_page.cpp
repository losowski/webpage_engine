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
	HTMLFormInputPtr key = df->add_text_input("key", "key", "update");
	key->setHidden();
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
	if ((false == getCGIEnvironment("key").empty()) && (true == m_id.empty()))
	{
		//Get QueryString
		string action = getCGIEnvironment("key");
		std::cerr << "We have a PAGE ID " <<  action << std::endl;
	}
	if ((false == getCGIEnvironment("id").empty()) && (true == m_id.empty()))
	{
		//Get QueryString
		m_id = getCGIEnvironment("id");
		std::cerr << "We have a PAGE ID " << std::endl;
	}


	if (itid != m_cgi->getElements().end() && itid->getValue().empty() == false)
	{
		m_id = itid->getValue();
		std::cerr << "We have a ID value for the form" << std::endl;
	}

	if (itforename != m_cgi->getElements().end() && itforename->getValue().empty() == false)
	{
		std::cerr << "BEFORE FORM NAME:" << m_forename << std::endl;
		m_forename = itforename->getValue();
		std::cerr << "FORM NAME:" << m_forename << std::endl;
	}
	if (ithappiness != m_cgi->getElements().end() && ithappiness->getValue().empty() == false)
	{
		m_happiness = ithappiness->getValue();
	}
	if (itcreation_date != m_cgi->getElements().end() && itcreation_date->getValue().empty() == false)
	{
		m_created_date = itcreation_date->getValue();
	}

}



void DemoPage::actionDataSelectSQL (pqxx::work & txn)
{
	//Run Query - Must be a traditional SQL statement and not a stored procedure.
	//		Those return a tuple for the ROW (1 column of concatenated strings) - incompatible
	//TODO: Perhaps a stored procedure here
	pqxx::result res = txn.exec("SELECT \
		id, \
		forename, \
		happiness, \
		created_date \
	FROM \
		demo_schema.tContact \
	WHERE \
		id = " + txn.quote(m_id) + ";");
	//for (pqxx::result::const_iterator row = res.begin(); row != res.end(); ++row) //Maybe try this out?
	for (pqxx::result::size_type i = 0; i != res.size(); ++i)
	{
		if (true == m_forename.empty())
		{
			m_forename.assign(res[i]["forename"].c_str());
		}
		if (true == m_happiness.empty())
		{
			m_happiness.assign(res[i]["happiness"].c_str());
		}
		if (true == m_created_date.empty())
		{
			m_created_date.assign(res[i]["created_date"].c_str());
		}
	}
	std::cerr << "FORM NAME SQL:" << m_forename << std::endl;
}

void DemoPage::actionDataUpdateSQL (pqxx::work & txn, const string & key)
{
	std::cerr << "Key = " << key << std::endl;
	pqxx::result res = txn.exec("demo_schema.pInsUpdContact(" + txn.quote(m_id) + ","  + txn.quote(m_forename) + ","  + txn.quote(m_happiness) +","  + txn.quote(m_created_date) +")");
	if (0 == res.affected_rows())
	{
		std::cerr << "Stuff changed" << std::endl;
	}
}




}
