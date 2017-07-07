#ifndef HTML_PAGE_HPP
#define HTML_PAGE_HPP

#include "html_title.hpp"
#include "html_form.hpp"

#include <string>
#include <list>
#include <boost/shared_ptr.hpp>

using namespace std;

namespace html {

typedef boost::shared_ptr<HTMLForm> HTMLFormPtr;

class HTMLPage {
	public:
		HTMLPage(void);
		HTMLPage(const string & title);
		~HTMLPage(void);
	public:
		void create_page(void);
		string get_page(void);
	public:
		/* Title */
		void add_title(HTMLTitle & title);
		HTMLTitle & get_title (void);
		/* Form */
		HTMLFormPtr add_form(const string & name, const string & action);
	private:
		string									m_html_page;
		HTMLTitle								m_html_title;
		list< HTMLFormPtr >						m_html_content; /* Should be common baseclass - form for now! */
};
}
#endif //HTML_PAGE_HPP
