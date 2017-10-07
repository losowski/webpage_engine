#ifndef HTML_ELEMENT_BASE_HPP
#define HTML_ELEMENT_BASE_HPP

#include <string>

using namespace std;

namespace html {

//Forward Definition
class HTMLElementBase;

class HTMLElementBase {
	public:
		HTMLElementBase(void);
		~HTMLElementBase(void);
	public:
		virtual void create_element(void) = 0;
		string get_element(void);
	protected:
		string								m_html_element;
};
}
#endif //HTML_ELEMENT_BASE_HPP
