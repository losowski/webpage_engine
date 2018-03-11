#include "web_site_cms.hpp"

using namespace std;
using namespace web;

int main (int argc, char * argv[])
{
	WebSiteCMS cms("CMS");
	WebPageBase * page = cms.createObjectFromKey();
	$CDN_MEDIA_PATH
	$CDN_JAVASCRIPT_PATH
	$CDN_CSS_PATH
	//Content
	$LOGO_TOP_MENU
	//Left Hand menu
	$LOGO_LEFT_HAND_MENU
	//Right Hand menu
	$LOGO_RIGHT_HAND_MENU
	//CGI
	page->connectDB("host=localhost dbname=cmsdb user=cms password=cmsdb");
	//page->parseCGI(); // REMOVED: Running this twice breaks everything!
	page->actionData();
	//Build
	page->buildWebsite();
	page->displayWebsite();
	//Cleanup
	cms.deleteObjectFromKey(page);
}

