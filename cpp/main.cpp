#include "html/html_page.hpp"
#include <iostream>
using namespace std;
using namespace html;

int main (int argc, char * argv[])
{
	//Demo Function
	HTMLPage page ("Hello World");
	page.create_page();
	HTMLFormPtr form = page.add_form("testing_form", "web01");
	form->add_text_input("nickname", "Pet Name", "otato");
	form->create_form();
	form->get_form();
	//form->add_button();
	std::cout << page.get_page() << std::endl;
}

