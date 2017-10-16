#ifndef HTML_BODY_ELEMENT_HPP
#define HTML_BODY_ELEMENT_HPP

#include "html_body_base.hpp"
#include "html_form.hpp"

#include <list>



using namespace std;

namespace html {

//typedef
typedef boost::shared_ptr<HTMLBodyBase> HTMLBodyBasePtr;

class HTMLBodyElement : public html::HTMLBodyBase
{
	public:
		HTMLBodyElement(void);
		HTMLBodyElement(const string & type, const string & name = "");
		~HTMLBodyElement(void);
	public:
		void create_html(void);
		void add_element(HTMLBodyBasePtr element);
	protected:
		list< HTMLBodyBasePtr >			m_html_body_content; /* Should be common baseclass - form for now! */

};
}
#endif //HTML_BODY_ELEMENT_HPP
