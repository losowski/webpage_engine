#ifndef WEB_PAGE_HPP
#define WEB_PAGE_HPP

#include "html_page.hpp"

using namespace std;

namespace web {

class WebPage: protected html::HTMLPage {
	public:
		WebPage(void);
		WebPage(const string & title);
		~WebPage(void);
	public:
		// Title
		// Top panel
		// Title Bar
		// Top menu
		// Left hand menu
		// Right hand menu
		// Bottom menu
		// Bottom panel
		// Main page area	
};
}
#endif //WEB_PAGE_HPP
