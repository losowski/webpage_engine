#ifndef HTML_SPAN_HPP
#define HTML_SPAN_HPP

#include "html_body_element.hpp"


using namespace std;

namespace html {

class HTMLSpan : public html::HTMLBodyElement
{
	public:
		HTMLSpan(void);
		~HTMLSpan(void);
};
}
#endif //HTML_SPAN_HPP
