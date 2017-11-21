#ifndef WEB_PAGE_CMS_HPP
#define WEB_PAGE_CMS_HPP

#include "web_page_base.hpp"

using namespace std;
using namespace html;

namespace web {

class WebPageCMS : public web::WebPageBase
{
	public:
		WebPageCMS(const string & title);
		~WebPageCMS(void);
	public:
		void cms_connect(const string & cms_database);
		void buildMainMenu(void);
	private:
			pqxx::connection *			m_cmsdb;
};
}
#endif //WEB_PAGE_CMS_HPP
