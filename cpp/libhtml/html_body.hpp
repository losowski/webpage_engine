#ifndef HTML_BODY_HPP
#define HTML_BODY_HPP

#include "html_form.hpp"

#include <string>
#include <list>

using namespace std;

namespace html {

class HTMLBody : public html::HTMLElement
{
	public:
		HTMLBody(void);
		~HTMLBody(void);
	public:
		void create_body(void);
		string get_body(void);
	public:
		/* Form */
		HTMLFormPtr add_form(const string & name, const string & action);
	private:
		string									m_html_body;
		HTMLTitle								m_html_title;
		list< HTMLHeaderPtr >					m_html_header_content;
		list< HTMLFormPtr >						m_html_content; /* Should be common baseclass - form for now! */

};
}
#endif //HTML_BODY_HPP
