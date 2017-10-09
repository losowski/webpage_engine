#ifndef HTML_BODY_ELEMENT_HPP
#define HTML_BODY_ELEMENT_HPP

#include <list>

#include "html_body_base.hpp"


using namespace std;

namespace html {

typedef boost::shared_ptr<HTMLBodyBase> HTMLBodyBasePtr;

class HTMLBodyElement : public html::HTMLBodyBase
{
	public:
		HTMLBodyElement(void);
		HTMLBodyElement(const string & type, const string & name = "");
		~HTMLBodyElement(void);
	public:
		virtual string create_html(void);
	public:
		/* Form */
		HTMLFormPtr add_form(const string & name, const string & action);
	protected:
		string							m_type;
		string							m_name;
	protected:
		list< HTMLBodyBasePtr >			m_html_body_content; /* Should be common baseclass - form for now! */

};
}
#endif //HTML_BODY_ELEMENT_HPP
