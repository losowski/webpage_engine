#include "demo_page.hpp"

using namespace std;
using namespace web;

int main (int argc, char * argv[])
{
	//Demo Function
	DemoPage demo("Fosters Contact Us");
	demo.TM_setPageTitle("Fosters Imaginary Friends");
	demo.setMediaPath("www");
	demo.setJavascriptPath("www");
	demo.setCSSPath("www");
	//Content
	demo.TM_addLogo("doggo.png");

	//Left Hand menu
	demo.LHM_addLogo("doggo2.png");
	demo.LHM_addMenuItem("home", "libwebpage.cgi", "Home Link");
	demo.RHM_addMenuItem("cgi-bin/index.html", "default");
	//CMS FUNCTIONS
	demo.actionData();
	//Build
	demo.buildWebsite();
	demo.displayWebsite();
}

