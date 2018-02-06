#ifndef WEB_SITE_HPP
#define WEB_SITE_HPP

#include "web_page_base_cgi.hpp"
#include "web_page_base.hpp"

#include <tuple>
#include <map>

using namespace std;
using namespace html;

namespace web {

class WebSiteCMS : public WebPageBaseCGI
{
	public:
		WebSiteCMS(void);
		~WebSiteCMS(void);
	public:
		WebPageBase * createObjectFromKey(void);
		WebPageBase * deleteObjectFromKey(WebPageBase * pagebase);
	private:
		void buildMenus(WebPageBase * pagebase);
	private:
		list < MenuItem >			m_menus;
};
}
#endif //WEB_SITE_HPP
