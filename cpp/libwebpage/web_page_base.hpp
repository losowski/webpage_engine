#ifndef WEB_PAGE_BASE_HPP
#define WEB_PAGE_BASE_HPP

#include "web_page_base_cgi.hpp"

#include "html_page.hpp"
#include "html_element_factory.hpp"


#include <tuple>
#include <list>

//Database
#include <pqxx/pqxx>

using namespace std;
using namespace html;

namespace web {

//Left Hand Menu Types
typedef tuple< string, string, string > MenuItem;
typedef tuple< string, string, string > AffiliateItem;


class WebPageBase : public WebPageBaseCGI
{
	public:
		WebPageBase(const string & title);
		WebPageBase(const string & title, cgicc::Cgicc * m_cgi);
		virtual ~WebPageBase(void);
	public:
		void connectDB(const string & connection);
		//void parseCGI(void); // IN base class
		//string getCGIEnvironment(const string & key);
		void actionData(void);
		// Media
		void setCDN(const string & cdn);
		void setMediaPath(const string & path);
		void setJavascriptPath(const string & path);
		void setCSSPath(const string & path);
		//Output
		void buildWebsite(void);
		void displayWebsite(void);
	public:
		// Top panel
		// Top Menu
		void TM_addLogo(const string & logo);
		void TM_setPageTitle(const string & header);
		// Left Hand Menu
		void LHM_addLogo(const string & logo);
		void LHM_addMenuItem(const string & name, const string & link, const string & text="");
		// Right hand menu
		void RHM_addMenuItem(const string & name, const string & link, const string & text="");
		// Main page area
		// Bottom menu
		void BM_addAffiliate(const string & logo, const string & link, const string & text="");
		void BM_addMenuItem(const string & name, const string & link, const string & text="");
		// Footer
	public:
		void addMenuItem(const string & name, const string & link, const string & text="");
	protected:
		virtual void actionDataSelectSQL(pqxx::work & txn) = 0;
		virtual void actionDataUpdateSQL(pqxx::work & txn, const string & key) = 0;
		virtual void actionDataCGI(void) = 0;
		//Header Functions
		void addJavascript(const string & filename);
		void addCSS(const string & filename);

		//call these base class functions to run
		// Building functions
		void buildTopPanel(void);
		void buildTopMenu(void);
		void buildTopMenuLowerPanel(void);
		void buildLeftMenu(void);
		virtual void buildMainMenu(void); // Override
		void buildRightMenu(void);
		void buildBottomMenu(void);
		void buildFooter(void);
	protected:
		//Generic
		string						m_id;
		string						m_cdn;
		string						m_media_path;
		string						m_javascript_path;
		string						m_css_path;
		HTMLPage					m_page;
		pqxx::connection *			m_dbconnection;
		// Top Menu
		string						m_tm_header;
		string						m_tm_header_logo;
		// Left Hand Menu
		string						m_lhm_logo;
		list < MenuItem >			m_lhm_menu_items;
		// Right hand menu
		list < MenuItem >			m_rhm_menu_items;
		// Main page area
		// Bottom menu
		list < AffiliateItem >		m_bm_affiliate;
		list < MenuItem >			m_bm_menu_items;
		// Footer
};
}
#endif //WEB_PAGE_BASE_HPP
