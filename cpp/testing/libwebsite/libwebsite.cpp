#include "web_page_base.hpp"

using namespace std;
using namespace web;

int main (int argc, char * argv[])
{
	//Demo Function
	WebPageBase wpb("Demo My Website");
	wpb.buildWebsite();
	wpb.displayWebsite();
}

