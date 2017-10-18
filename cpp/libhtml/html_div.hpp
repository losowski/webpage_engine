#ifndef HTML_DIV_HPP
#define HTML_DIV_HPP

#include "html_body_element.hpp"


using namespace std;

namespace html {

class HTMLDiv : public html::HTMLBodyElement
{
	public:
		HTMLDiv(void);
		~HTMLDiv(void);
};
}
#endif //HTML_DIV_HPP
