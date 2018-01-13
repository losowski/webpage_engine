$HEADER_INCLUDE

//Libpxx
#include <pqxx/cursor>
#include <pqxx/transaction>
#include <pqxx/result>

using namespace std;
using namespace html;
using namespace cgicc;

namespace web {

$CLASS_NAME::$CLASS_NAME(const string & title):
		web::WebPageBase ( title )
{

}

$CLASS_NAME::~$CLASS_NAME(void)
{
}
//Public
void $CLASS_NAME::buildMainMenu(void)
{
	//Style
	addCSS("demo-layout");
	//Scripts
	//HTML
	HTMLBodyBasePtr demo = m_page.add_div("demo-layout");
	//MENU
	HTMLFormPtr df = HTMLElementFactory::add_form(demo, "demoform", "$CLASS_NAME.cgi");
	HTMLFormInputPtr key = df->add_text_input("key", "key", "update");
	key->setHidden();
	{BUILD_PRIMARY_KEY}
	{BUILD_FIELDS}
	df->set_submit_name("Enter");
}

void $CLASS_NAME::actionDataCGI(void)
{
	// Setting the Key
	parseCGIKey();
	// Setting the id value
	parseCGIPrimaryKey(m_id, "id");
	// Setting the forename value
$PARSE_CGI_PARAMETERS
}



void $CLASS_NAME::actionDataSelectSQL (pqxx::work & txn)
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
$PROCESS_SQL_RESULT
	}
}

void $CLASS_NAME::actionDataUpdateSQL (pqxx::work & txn, const string & key)
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
