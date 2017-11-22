#include "web_page_cms.hpp"

using namespace std;
using namespace web;

int main (int argc, char * argv[])
{
	//Demo Function
	WebPageCMS wpc("Fosters");
	wpc.TM_setPageTitle("Fosters Imaginary Friends");
	//Javascript
	wpc.addJavascript("fosters");
	//Content
	wpc.TM_addLogo("doggo.png");
	//Left Hand menu
	wpc.LHM_addLogo("doggo2.png");
	wpc.LHM_addMenuItem("cgi-bin/libwebpage.cgi", "Home Link");
	wpc.RHM_addMenuItem("cgi-bin/index.html", "default");
	//Build
	wpc.buildWebsite();
	wpc.displayWebsite();
}

