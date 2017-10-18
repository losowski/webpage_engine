#include "html_element_factory.hpp"
#include <iostream>
using namespace std;
using namespace html;

int main (int argc, char * argv[])
{
	//Demo Function
	HTMLPagePtr page = HTMLElementFactory::create_page("Hello World");
	page->add_script("demo");
	page->add_style("gangnam");
	page->add_meta_data(header::HTMLHeaderMeta::HTML_META_KEYWORDS, "Demo, Super");
	HTMLElementFactory::add_div(page, "divider1");
	HTMLElementFactory::add_div(page, "divider1");
	HTMLFormPtr form = page->add_form("testing_form", "web01");
	form->add_password_input("pword", "Secret Word");
	form->add_text_input("nickname", "Pet Name");
	form->add_text_input("realname", "Full Name", "Dictator Otato");
	form->add_radio_input("gender", "Male", "male");
	form->add_radio_input("gender", "Female", "female");
	HTMLElementFactory::add_h1(form, "divider2", "Animals");
	HTMLFormInputMenuPtr menu = form->add_menu_input("animals", "Select an Animal");
	menu->add_menu_selection("Cat", "cat");
	menu->add_menu_selection("Dog", "dog", false);
	menu->add_menu_selection("Goat", "goat", true);
	menu->add_menu_selection("Unicorn", "Unicorn");
	form->add_reset_input();
	//form->add_button();
	page->create_html();
	std::cout << page->get_html() << std::endl;
}

