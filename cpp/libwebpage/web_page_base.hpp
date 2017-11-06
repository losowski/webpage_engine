#ifndef WEB_PAGE_BASE_HPP
#define WEB_PAGE_BASE_HPP

#include "html_page.hpp"
#include "html_element_factory.hpp"

using namespace std;
using namespace html;

namespace web {

class WebPageBase
{
	public:
		WebPageBase(const string & title);
		~WebPageBase(void);
	public:
		// Media
		void set_cdn(const string & cdn);
		void set_media_path(const string & path);
		// Top Menu
		void setPageTitle(const string & header);
		// Title
		// Top panel
		// Title Bar
		// Top menu
		// Left hand menu
		// Right hand menu
		// Bottom menu
		// Bottom panel
		// Main page area
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
		string				m_cdn;
		string				m_media_path;
		HTMLPage			m_page;
		string				m_header;
};
}
#endif //WEB_PAGE_BASE_HPP
