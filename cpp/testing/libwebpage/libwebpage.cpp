#include "web_page_default.hpp"

using namespace std;
using namespace web;

int main (int argc, char * argv[])
{
	//Demo Function
	WebPageDefault wpb("Demo My Website");
	wpb.buildWebsite();
	wpb.displayWebsite();
}

