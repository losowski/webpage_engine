#include "web_page.hpp"

using namespace std;

namespace web {

WebPage::WebPage(void): html::HTMLPage("Test Web Page")
{
}

WebPage::WebPage(const string & title):	HTMLPage(title)
{
	
}

WebPage::~WebPage(void)
{
}


}
