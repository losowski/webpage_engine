#ifndef DEMO_PAGE_HPP
#define DEMO_PAGE_HPP

#include "web_page_base.hpp"

using namespace std;
using namespace html;

namespace web {

class DemoPage : public web::WebPageBase
{
	public:
		DemoPage(const string & title);
		~DemoPage(void);
	public:
		void actionData(void);
		void buildMainMenu(void);
};
}
#endif //DEMO_PAGE_HPP
