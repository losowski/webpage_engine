#include "web_site_cms.hpp"

using namespace std;
using namespace html;

namespace web {

WebSiteCMS::WebSiteCMS(const string & title):
	web::WebPageBase ( title ),
	m_title(title)
{
	buildMenus();
	// m_lhm_menu_items
	//m_pages = map < class, class constructor >
}

WebSiteCMS::~WebSiteCMS(void)
{
}

void WebSiteCMS::buildMenus(void)
{
	m_rhm_menu_items.assign (m_lhm_menu_items.begin(), m_lhm_menu_items.end());
	m_bm_menu_items.assign (m_lhm_menu_items.begin(), m_lhm_menu_items.end());
}

void WebSiteCMS::actionData(void)
{
	// Setting the Key
	parseCGIKey();
	//Build the object
	tpagemap::iterator itpage = m_pages.find(m_cgikey);
	web::WebPageBase page  = itpage->second(m_title);
	page.parseCGI();
	page.actionData();
	page.buildWebsite();
	page.displayWebsite();

}
