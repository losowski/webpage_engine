#include "web_page_default.hpp"

using namespace std;
using namespace html;
using namespace cgicc;

namespace web {

WebPageDefault::WebPageDefault(const string & title):
		web::WebPageBase ( title ),
		m_text ("Adopt Cheese! - He likes chocolate milk")
{
}

WebPageDefault::WebPageDefault(const string & title, cgicc::Cgicc * m_cgi):
		web::WebPageBase (title, m_cgi),
		m_text ("Adopt Cheese! - He likes chocolate milk")
{
}

WebPageDefault::~WebPageDefault(void)
{
}
//Public
void WebPageDefault::buildMainMenu(void)
{
	//Style
	addCSS("default-layout");
	//Scripts
	//HTML
	HTMLBodyBasePtr tm = m_page.add_div("default-layout");
	HTMLFormPtr df = HTMLElementFactory::add_form(tm, "defaultform", "libwebsite.cgi");
	df->add_text_input("text", "Message for Fosters", m_text);
	df->set_submit_name("Enter");
}

void WebPageDefault::actionDataCGI(void)
{
	/*
		Code design
		1) Get the form in the class cgicc::FormEntry
			cgicc::form_iterator it = m_cgi->getElement("libwebsite.cgi");
		2) For each field in the named form, get the data using "getValue"
	*/
	// -- Iterators
	cgicc::form_iterator ittext = m_cgi->getElement("libwebsite.cgi");
	// -- Setting the values
	if (ittext != m_cgi->getElements().end() && ittext->getValue().empty() == false)
	{
		m_text = ittext->getValue();
	}
}

void WebPageDefault::actionDataSelectSQL(pqxx::work & txn)
{
}

void WebPageDefault::actionDataUpdateSQL (pqxx::work & txn, const string & key)
{
}

}
