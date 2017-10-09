#ifndef HTML_BODY_HPP
#define HTML_BODY_HPP

#include <list>

#include "html_body_element.hpp"


using namespace std;

namespace html {

class HTMLBody : public html::HTMLBodyElement
{
	public:
		HTMLBody(void);
		~HTMLBody(void);
};
}
#endif //HTML_BODY_HPP
