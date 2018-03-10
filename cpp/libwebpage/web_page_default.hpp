#ifndef WEB_PAGE_DEFAULT_HPP
#define WEB_PAGE_DEFAULT_HPP

#include "web_page_base.hpp"

using namespace std;
using namespace html;

namespace web {

class WebPageDefault : public web::WebPageBase
{
	public:
		WebPageDefault(const string & title);
		WebPageDefault(const string & title, cgicc::Cgicc * m_cgi);
		~WebPageDefault(void);
	public:
		void actionDataCGI(void);
		void actionDataSelectSQL(pqxx::work & txn);
		void actionDataUpdateSQL (pqxx::work & txn, const string & key);
		void buildMainMenu(void);
	public:
		string		m_text;
};
}
#endif //WEB_PAGE_DEFAULT_HPP
