#ifndef HTML_ELEMENT_HPP
#define HTML_ELEMENT_HPP

#include "html_element_base.hpp"

#include <list>
#include <boost/shared_ptr.hpp>

using namespace std;

namespace html {

typedef boost::shared_ptr<HTMLElementBase> HTMLElementBasePtr;

class HTMLElement : public html::HTMLElementBase
{
	public:
		HTMLElement(void);
		~HTMLElement(void);
	public:
		virtual void create_element(void) = 0;
	public:
		//helper functions - Calls create_element on the sub elements
		void create_sub_elements(void);
	private:
		list< HTMLElementBasePtr >					m_html_element_list;
};

}
#endif //HTML_ELEMENT_HPP
