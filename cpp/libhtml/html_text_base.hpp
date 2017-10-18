#ifndef HTML_TEXT_BASE_HPP
#define HTML_TEXT_BASE_HPP

#include "html_body_element.hpp"


using namespace std;

namespace html {

class HTMLTextBase : public html::HTMLBodyElement
{
	public:
		HTMLTextBase(const string & name, const string & text);
		~HTMLTextBase(void);
	protected:
		string				m_text;
};
}
#endif //HTML_TEXT_BASE_HPP
