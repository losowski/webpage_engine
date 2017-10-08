#ifndef HTML_BODY_HPP
#define HTML_BODY_HPP

#include <list>

#include "html_body_base.hpp"


using namespace std;

namespace html {

//typedef boost::shared_ptr<HTMLBodyBase> HTMLBodyBasePtr;
typedef boost::shared_ptr<HTMLBase> HTMLBasePtr;

class HTMLBody : public html::HTMLBodyBase
{
	public:
		HTMLBody(void);
		~HTMLBody(void);
	public:
		void create_body(void);
	public:
		/* Form */
		HTMLFormPtr add_form(const string & name, const string & action);
	private:
		list< HTMLBasePtr >					m_html_body_content; /* Should be common baseclass - form for now! */

};
}
#endif //HTML_BODY_HPP
