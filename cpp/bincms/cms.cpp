#include "web_page_cms.hpp"

using namespace std;
using namespace web;

int main (int argc, char * argv[])
{
	WebSiteCMS cms("CMS");
	WebPageBase * page = createObjectFromKey();
	//CGI
	page.connectDB("host=localhost dbname=demodb user=demo password=demodb");
	page.parseCGI();
	page.actionData();
	//Build
	page.buildWebsite();
	page.displayWebsite();
	deleteObjectFromKey(page);
}

