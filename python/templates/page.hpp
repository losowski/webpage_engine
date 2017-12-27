#ifndef {HEADER_IFDEF}_HPP
#define {HEADER_IFDEF}_HPP

#include "web_page_base.hpp"

using namespace std;
using namespace html;

namespace web {

class {CLASS_NAME} : public web::WebPageBase
{
	public:
		{CLASS_NAME}(const string & title);
		~{CLASS_NAME}(void);
	public:
		void actionDataCGI(void);
		void actionDataSelectSQL(pqxx::work & txn);
		void actionDataUpdateSQL (pqxx::work & txn, const string & key);
		void buildMainMenu(void);
	private:
		string				m_id;
		string				m_forename;
		string				m_happiness;
		string				m_created_date;
};
}
#endif //{HEADER_IFDEF}_HPP
