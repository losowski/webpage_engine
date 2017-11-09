#ifndef WEB_PAGE_BASE_HPP
#define WEB_PAGE_BASE_HPP

#include "html_page.hpp"
#include "html_element_factory.hpp"

#include <tuple>
#include <list>

using namespace std;
using namespace html;

namespace web {

//Left Hand Menu Types
typedef tuple< string , string> LHMItem;


class WebPageBase
{
	public:
		WebPageBase(const string & title);
		~WebPageBase(void);
	public:
		// Media
		void set_cdn(const string & cdn);
		void set_media_path(const string & path);
		void set_javascriptPath(const string & path);
		void set_cssPath(const string & path);
		//Header Functions
		void H_addJavascript(const string & filename);
		void H_addCSS(const string & filename);
		// Top panel
		// Top Menu
		void TM_addLogo(const string & logo);
		void TM_setPageTitle(const string & header);
		// Left Hand Menu
		void LHM_addLogo(const string & logo);
		void LHM_addMenuItem(const string & link, const string & text);
		// Right hand menu
		// Main page area
		// Bottom menu
		// Footer
		// Footer Panel
	//call these base class functions to run
		//void create_page(void);
		//string get_page(void);
		void buildWebsite(void);
		void displayWebsite(void);
	protected:
		// Building functions
		void buildTopPanel(void);
		void buildTopMenu(void);
		void buildTopMenuLowerPanel(void);
		void buildLeftMenu(void);
		void buildRightMenu(void);
		void buildBottomMenu(void);
		void buildFooter(void);
		void buildFooterPanel(void);
	protected:
		//Generic
		string						m_cdn;
		string						m_media_path;
		string						m_javascript_path;
		string						m_css_path;
		HTMLPage					m_page;
		// Top Menu
		string						m_tm_header;
		string						m_tm_header_logo;
		// Left Hand Menu
		string						m_lhm_logo;
		list < LHMItem >			m_lhm_menu_items;
		// Right hand menu
		// Main page area
		// Bottom menu
		// Footer
		// Footer Panel

};
}
#endif //WEB_PAGE_BASE_HPP
