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
	HTMLBodyBasePtr text = HTMLElementFactory::add_text(tm, m_text);
}

void WebPageDefault::actionDataCGI(void)
{
// -- Iterators
	const_form_iterator ittext = m_cgi->getElement("text");
	// -- Setting the values
	if (ittext != m_cgi->getElements().end() && ittext->getValue().empty() == false)
	{
		m_text = ittext->getValue();
	}
}

void WebPageDefault::actionDataSQL (void)
{
}


}
