#include "web_page_cms.hpp"

using namespace std;
using namespace html;

namespace web {

WebPageCMS::WebPageCMS(const string & title):
		web::WebPageBase ( title )
{

}

WebPageCMS::~WebPageCMS(void)
{
	//Hopefully Clean the m_dbconnection object
	if (this->m_cmsdb != NULL)
	{
		delete this->m_cmsdb;
	}
}
void WebPageCMS::cms_connect(const string & cms_database)
{
	try
	{
		// Connect to the database
		m_cmsdb = new pqxx::connection(cms_database);
	}
	catch (const pqxx::sql_error &e)
	{
		std::cerr << "CMS SQL error: " << e.what() << std::endl;
		std::cerr << "CMS Query was: " << e.query() << std::endl;
		exit(EXIT_FAILURE);
	}
	catch (const std::exception &e)
	{
		std::cerr << "CMS Error: " << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
}

//Public
void WebPageCMS::buildMainMenu(void)
{
	//CMS Driven override of this class
}

}
