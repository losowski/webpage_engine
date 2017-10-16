#ifndef HTML_PAGE_HPP
#define HTML_PAGE_HPP

#include "html_title.hpp"
#include "html_form.hpp"
#include "html_header_script.hpp"
#include "html_header_style.hpp"
#include "html_header_meta.hpp"

#include <string>
#include <list>
#include <boost/shared_ptr.hpp>

using namespace std;

namespace html {


typedef boost::shared_ptr<header::HTMLHeader> HTMLHeaderPtr;

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
		/* Header */
		void add_script(const string & url);
		void add_style(const string & url);
		/* Only allowed once */
		void add_meta_data(const header::MetaType & type, const string & content);

		/* Form */
		HTMLFormPtr add_form(const string & name, const string & action);
	private:
		string									m_html_page;
		HTMLTitle								m_html_title;
		list< HTMLHeaderPtr >					m_html_header_content;
		list< HTMLFormPtr >						m_html_content; /* Should be common baseclass - form for now! */
	
};
}
#endif //HTML_PAGE_HPP
