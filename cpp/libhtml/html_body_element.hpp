#ifndef HTML_BODY_ELEMENT_HPP
#define HTML_BODY_ELEMENT_HPP

#include "html_body_base.hpp"
//#include "html_form.hpp"


using namespace std;

namespace html {

class HTMLBodyElement : public html::HTMLBodyBase
{
	public:
		HTMLBodyElement(const string & type, const string & name = "");
		~HTMLBodyElement(void);
	public:
		//void create_html(void); // Override
};

typedef boost::shared_ptr< HTMLBodyElement > HTMLBodyElementPtr;

}
#endif //HTML_BODY_ELEMENT_HPP
