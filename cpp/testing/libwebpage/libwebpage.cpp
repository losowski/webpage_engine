#include "web_page_default.hpp"

using namespace std;
using namespace web;

int main (int argc, char * argv[])
{
	//Demo Function
	WebPageDefault wpb("Fosters");
	wpb.TM_setPageTitle("Fosters Imaginary Friends");
	wpb.setMediaPath("www");
	wpb.setJavascriptPath("www");
	wpb.setCSSPath("www");
	//Content
	wpb.TM_addLogo("doggo.png");
	//Left Hand menu
	wpb.LHM_addLogo("doggo2.png");
	wpb.LHM_addMenuItem("cgi-bin/libwebpage.cgi", "Home Link");
	wpb.RHM_addMenuItem("cgi-bin/index.html", "default");
	//Build
	wpb.buildWebsite();
	wpb.displayWebsite();
}

