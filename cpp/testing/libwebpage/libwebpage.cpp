#include "web_page_default.hpp"

using namespace std;
using namespace web;

int main (int argc, char * argv[])
{
	//Demo Function
	WebPageDefault wpb("Fosters");
	wpb.TM_setPageTitle("Fosters Imaginary Friends");
	wpb.TM_addLogo("doggo.png");
	wpb.LHM_addLogo("doggo2.png");
	wpb.LHM_addMenuItem("cgi-bin/libwebpage.cgi", "Home Link");
	wpb.buildWebsite();
	wpb.displayWebsite();
}

