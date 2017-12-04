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
	// Output the form
	//Style
	addCSS("default-layout");
	//Scripts
	//HTML
	HTMLBodyBasePtr demo = m_page.add_div("demo-layout");
	//MENU
	HTMLFormPtr df = HTMLElementFactory::add_form(demo, "demoform", "libdemosite.cgi");
	df.add_text_input("id", "id", id);
	df.add_text_input("forename", "forename", forename);
	df.add_text_input("happiness", "happiness", happiness);
	df.add_text_input("creation_date", "creation_date", creation_date);
	df.set_submit_name("Enter");
}

void DemoPage::actionData(void)
{
	//Get Data from the CGI form
	string id = m_cgi->cgi("id");
	string forename = cgi("forename");
	string happiness = cgi("happiness");
	string creation_date = cgi("creation_date");
	//Call the SQL
	// Output the form
	//Style
	addCSS("default-layout");
	//Scripts
	//HTML
	HTMLBodyBasePtr demo = m_page.add_div("demo-layout");
	//MENU
	HTMLFormPtr df = HTMLElementFactory::add_form(demo, "demoform", "libdemosite.cgi");
	df.add_text_input("id", "id", id);
	df.add_text_input("forename", "forename", forename);
	df.add_text_input("happiness", "happiness", happiness);
	df.add_text_input("creation_date", "creation_date", creation_date);
	df.set_submit_name("Enter");
}

}
