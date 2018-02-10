#include "web_site_cms.hpp"

using namespace std;
using namespace web;

int main (int argc, char * argv[])
{
	WebSiteCMS cms("CMS");
	WebPageBase * page = cms.createObjectFromKey();
	//CGI
	page->connectDB("host=localhost dbname=cmsdb user=cms password=cmsdb");
	page->parseCGI();
	page->actionData();
	//Build
	page->buildWebsite();
	page->displayWebsite();
	//Cleanup
	cms.deleteObjectFromKey(page);
}

