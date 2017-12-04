#ifndef WEB_PAGE_BASE_HPP
#define WEB_PAGE_BASE_HPP

#include "html_page.hpp"
#include "html_element_factory.hpp"

#include <tuple>
#include <list>

//CGI
#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

//Database
#include <pqxx/pqxx>

using namespace std;
using namespace html;

namespace web {

//Left Hand Menu Types
typedef tuple< string, string, string > MenuItem;
typedef tuple< string, string, string > AffiliateItem;


class WebPageBase
{
	public:
		WebPageBase(const string & title);
		~WebPageBase(void);

	protected:
		void parse(void); // Override
	public:
		void connect(const string & connection);
		void actionData(void);
		virtual void actionDataCGI(void) = 0;
		virtual void actionDataSQL(void) = 0;
		// Media
		void setCDN(const string & cdn);
		void setMediaPath(const string & path);
		void setJavascriptPath(const string & path);
		void setCSSPath(const string & path);
		//Header Functions
		void addJavascript(const string & filename);
		void addCSS(const string & filename);
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
		//call these base class functions to run
		void buildWebsite(void);
		void displayWebsite(void);
	protected:
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
		string						m_cdn;
		string						m_media_path;
		string						m_javascript_path;
		string						m_css_path;
		HTMLPage					m_page;
		cgicc::Cgicc *				m_cgi;
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
