#include "web_site.hpp"

$CGI_INCLUDE
#include <boost/foreach.hpp>

using namespace std;
using namespace html;

WebSiteCMS::WebSiteCMS(string & title):
	web::WebPageBaseCGI (),
	m_page(title)
{
}

WebSiteCMS::~WebSiteCMS(void)
{
}

WebPageBase * WebSiteCMS::createObjectFromKey(void)
{
	WebPageBase * object = NULL;
	// Setting the Key
	parseCGIKey();
	if (true = m_cgikey.empty())
	{
		object = new $CGI_DEFAULT_PAGE ;
	}
	else
	{	switch (m_cgikey)
		{
			$CGI_BUILD_SITE_MAP
			default:
				object = new $CGI_DEFAULT_PAGE ;
		}
		
	}
	//Build menus
	buildMenus(object);
	return object;
}

WebPageBase * WebSiteCMS::deleteObjectFromKey(WebPageBase * pagebase)
{
	if (NULL != pagebase)
	{
		delete pagebase;
		pagebase = NULL;
	}
	return pagebase;
}

void WebSiteCMS::buildMenus(WebPageBase * pagebase);
{
	list < MenuItem > itemlist = \
$CGI_MENU_ITEMS ;
	//Add the Menu Entries
	BOOST_FOREACH(MenuItem item, itemlist)
	{
		pagebase->addMenuItem (get<0>(item), get<1>(item), get<2>(item));
	}
}
