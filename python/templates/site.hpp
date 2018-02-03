#ifndef WEB_SITE_CMS_HPP
#define WEB_SITE_CMS_HPP

#include "web_page_base.hpp"

using namespace std;
using namespace html;

namespace web {

typedef map < string, void(*)(string & title) > tpagemap;

class WebSiteCMS : public web::WebPageBase
{
	public:
		WebSiteCMS(const string & title);
		~WebSiteCMS(void);
	protected:
	/* // Menu items to fill in
		list < MenuItem >			m_lhm_menu_items;
		list < MenuItem >			m_rhm_menu_items;
		list < MenuItem >			m_bm_menu_items;
	*/
	private:
		void buildMenus(void);
		//Override normal CGI behaviour to run own magic script
		void actionData(void);
	private:
		string		m_title;
		tpagemap 	m_pages;
		
};
}
#endif //WEB_SITE_CMS_HPP

