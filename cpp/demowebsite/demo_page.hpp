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
		void actionDataCGI(void);
		void actionDataSelectSQL(pqxx::work & txn);
		void actionDataUpdateSQL (pqxx::work & txn, const string & key);
		void buildMainMenu(void);
	private:
		string				m_forename;
		string				m_happiness;
		string				m_created_date;
};
}
#endif //DEMO_PAGE_HPP
