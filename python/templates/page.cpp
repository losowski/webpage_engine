$HEADER_INCLUDE

//Libpxx
#include <pqxx/cursor>
#include <pqxx/transaction>
#include <pqxx/result>

using namespace std;
using namespace html;
using namespace cgicc;

namespace web {

$CLASS_NAME::$CLASS_NAME(const string & title, cgicc::Cgicc * m_cgi):
		web::$RAWDATA_BASE_CLASS ( title, m_cgi )
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
	HTMLFormPtr df = HTMLElementFactory::add_form(demo, "demoform", "$BINARY_NAME.cgi");
	HTMLFormInputPtr key = df->add_text_input("page", "page", "$rawdata_file_name");
	key->setHidden();
	HTMLFormInputPtr id = df->add_text_input("id", "id", m_id);
	id->setHidden();
$BUILD_CGI_DESIGN
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
	pqxx::result res = txn.exec("SELECT \
		$SQL_SELECT \
	FROM \
		$SQL_SCHEMA_TABLE \
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
	pqxx::result res = txn.exec("SELECT $SQL_STOREDPROCNAME(" + m_id $SQL_STORED_PROCEDURE_PARAMETERS + ")");
	for (pqxx::result::size_type i = 0; i != res.size(); ++i)
	{
		if ("NULL" == m_id)
		{
			m_id.assign(res[i]["$SQL_STOREDPROC_COL"].c_str());
			PrimaryKeySet();
		}
	}
	txn.commit();
}

}
