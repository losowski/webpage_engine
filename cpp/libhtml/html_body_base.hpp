#ifndef HTML_BODY_BASE_HPP
#define HTML_BODY_BASE_HPP

#include "html_base.hpp"

//#include <boost/shared_ptr.hpp>

using namespace std;

namespace html {


class HTMLBodyBase : public html::HTMLBase
{
	public:
		HTMLBodyBase(const string & type, const string & name = "");
		~HTMLBodyBase(void);
	public:
		/* Create body must be virtual */
		virtual void create_html(void) = 0;
		//virtual add_element(HTMLBodyBasePtr element) = 0; //Need this function
	protected:
		string				m_type;
		string				m_name;

};



}
#endif //HTML_BODY_BASE_HPP
