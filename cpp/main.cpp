#include "html/html_page.hpp"
#include <iostream>
using namespace std;
using namespace html;

int main (int argc, char * argv[])
{
	//Demo Function
	HTMLPage page ("Hello World");
	page.create_page();
	std::cout << page.get_page() << std::endl;
}

