#ifndef HTML_BODY_ELEMENT_HPP
#define HTML_BODY_ELEMENT_HPP

#include "html_body_base.hpp"
#include "html_form.hpp"


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
		//void create_html(void); // Override
	HTMLFormPtr add_form(const string & name, const string & action)
};
}
#endif //HTML_BODY_ELEMENT_HPP
