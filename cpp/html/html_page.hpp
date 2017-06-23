#ifndef HTML_PAGE_HPP
#define HTML_PAGE_HPP

#include <string>
#include "html_title.hpp"

using namespace std;

namespace html {
class HTMLPage {
	public:
		HTMLPage(void);
		HTMLPage(const string & title);
		~HTMLPage(void);
	public:
		void create_page(void);
		string get_page(void);
	public:
		void add_title(HTMLTitle & title);
		HTMLTitle & get_title (void);
	private:
		string		m_html_page;
		HTMLTitle	m_html_title;
};
}
#endif //HTML_PAGE_HPP
