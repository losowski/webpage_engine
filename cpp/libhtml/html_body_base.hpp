#ifndef HTML_BODY_BASE_HPP
#define HTML_BODY_BASE_HPP


#include "html_base.hpp"
// Special Functions
#include "html_form.hpp"

using namespace std;

namespace html {
class HTMLForm;

typedef boost::shared_ptr<HTMLForm> HTMLFormPtr;

class HTMLBodyBase : public html::HTMLBase
{
	public:
		HTMLBodyBase(void);
		~HTMLBodyBase(void);
	public:
		/* Create body must be virtual */
		virtual void create_html(void) = 0;
	public:
		/* Form */
		virtual HTMLFormPtr add_form(const string & name, const string & action) = 0;

};
}
#endif //HTML_BODY_BASE_HPP
