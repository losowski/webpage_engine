#include "web_page_default.hpp"

using namespace std;
using namespace html;

namespace web {

WebPageDefault::WebPageDefault(const string & title):
		web::WebPageBase ( title )
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
	HTMLBodyBasePtr text = HTMLElementFactory::add_text(tm, "Adopt Cheese! - He likes chocolate milk");
}

void WebPageDefault::actionData(void)
{
}


}
