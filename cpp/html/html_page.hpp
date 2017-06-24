#ifndef HTML_PAGE_HPP
#define HTML_PAGE_HPP

#include "html_title.hpp"
#include "html_form.hpp"

#include <string>
#include <list>
#include <boost/shared_ptr.hpp>

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
		/* Title */
		void add_title(HTMLTitle & title);
		HTMLTitle & get_title (void);
		/* Form */
		boost::shared_ptr<HTMLForm> add_form(void);
	private:
		string									m_html_page;
		HTMLTitle								m_html_title;
		list< boost::shared_ptr<HTMLForm> >		m_html_content; /* Should be common baseclass - form for now! */
};
}
#endif //HTML_PAGE_HPP
