#include "html/html_page.hpp"
#include <iostream>
using namespace std;
using namespace html;

int main (int argc, char * argv[])
{
	//Demo Function
	HTMLPage page ("Hello World");
	HTMLFormPtr form = page.add_form("testing_form", "web01");
	form->add_text_input("nickname", "Pet Name");
	form->add_text_input("realname", "Full Name", "Dictator Otato");
	form->add_radio_input("gender", "Male", "male");
	form->add_radio_input("gender", "Female", "female");
	//form->add_button();
	page.create_page();
	std::cout << page.get_page() << std::endl;
}

