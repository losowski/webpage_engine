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
	//Style
	addCSS("demo-page-layout");
	//Scripts
	//Menu
	HTMLBodyBasePtr tm = m_page.add_span("default-layout");
	HTMLBodyBasePtr text = HTMLElementFactory::add_text(tm, "Adopt Cheese! - He likes chocolate milk");
}

void DemoPage::actionData(void)
{
}

}
