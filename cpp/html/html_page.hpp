#ifndef HTML_PAGE_HPP
#define HTML_PAGE_HPP

#include <string>
#include "html_title.hpp"

using namespace std;

namespace html {
class HTMLPage {
	public:
		HTMLPage(void);
		~HTMLPage(void);
	public:
		string create_page(void);
	public:
		void add_title(HTMLTitle & title);
	private:
		HTMLTitle m_html_title;
};
}
#endif //HTML_PAGE_HPP
