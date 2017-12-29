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
		web::WebPageBase ( title ),
		m_id ("NULL")
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
	HTMLFormInputPtr id = df->add_text_input("id", "id", m_id);
	id->setHidden();
	df->add_text_input("forename", "Forename", m_forename);
	df->add_text_input("happiness", "Happiness Level", m_happiness);
	df->add_text_input("creation_date", "Creation Date", m_created_date);
	df->set_submit_name("Enter");
}

void DemoPage::actionDataCGI(void)
{
	// Setting the Key
	void parseCGIKey(void);
	// Setting the id value
	parseCGIPrimaryKey(m_id, "id");
	// Setting the forename value
	parseCGIParameter(m_forename, "forename");
	parseCGIParameter(m_happiness, "happiness");
	parseCGIParameter(m_created_date, "creation_date");
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
}

void DemoPage::actionDataUpdateSQL (pqxx::work & txn, const string & key)
{
	pqxx::result res = txn.exec("SELECT demo_schema.pInsUpdContact(" + m_id + ","  + txn.quote(m_forename) + ","  + txn.quote(m_happiness) +","  + txn.quote(m_created_date) +")");
	for (pqxx::result::size_type i = 0; i != res.size(); ++i)
	{
		if ("NULL" == m_id)
		{
			m_id.assign(res[i]["pInsUpdContact"].c_str());
			PrimaryKeySet();
		}
	}
	txn.commit();
}

}
