#ifndef WEB_PAGE_DEFAULT_HPP
#define WEB_PAGE_DEFAULT_HPP

#include "web_page_base.hpp"

//TODO: Some how this broke it!. Fix ASAP
using namespace std;
using namespace html;

namespace web {

class WebPageDefault : public web::WebPageBase
{
	public:
		WebPageDefault(const string & title);
		~WebPageDefault(void);
};
}
#endif //WEB_PAGE_DEFAULT_HPP
