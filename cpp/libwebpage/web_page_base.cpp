#include "web_page_base.hpp"
#include "html_element_factory.hpp"


#include <iostream>
#include <boost/foreach.hpp>

using namespace std;
using namespace html;

namespace web {

#define PAGE_CDN(image){ m_cdn + m_media_path + image}

WebPageBase::WebPageBase(const string & title):
		m_cdn ("//localhost/"),
		m_page ( title )
{
}

WebPageBase::~WebPageBase(void)
{
}

//Build the page
void WebPageBase::set_cdn(const string & cdn)
{
	m_cdn = "//" + cdn + "/";
}

void WebPageBase::set_media_path(const string & path)
{
	m_media_path = path;
}

void WebPageBase::set_javascriptPath(const string & path)
{
	m_javascript_path = path;
}

void WebPageBase::set_cssPath(const string & path)
{
	m_css_path = path;
}


//Header Functions
//TODO: Include SEO functions (meta tag)
void WebPageBase::addJavascript(const string & filename)
{
	m_page.add_script(m_javascript_path + filename);
}

void WebPageBase::addCSS(const string & filename)
{
	m_page.add_style(m_css_path + filename);
}

// Top panel
void WebPageBase::buildTopPanel(void)
{
	HTMLBodyBasePtr toppanel = m_page.add_span("top-panel");
}

// Top Menu
void WebPageBase::TM_addLogo(const string & logo)
{
	m_tm_header_logo = logo;
}

void WebPageBase::TM_setPageTitle(const string & header)
{
	m_tm_header = header;
}

void WebPageBase::buildTopMenu(void)
{
	HTMLBodyBasePtr tm = m_page.add_span("top-menu");
	HTMLBodyBasePtr tmspanlogo = HTMLElementFactory::add_span(tm, "logo");
	HTMLBodyBasePtr tmlogo = HTMLElementFactory::add_image(tmspanlogo, m_tm_header_logo, PAGE_CDN(m_tm_header_logo), m_tm_header_logo);
	HTMLBodyBasePtr tmheader = HTMLElementFactory::add_span(tm, "header-title");
	HTMLElementFactory::add_h1(tmheader, "header-title", m_tm_header);
}
// Top Menu Lower Panel
void WebPageBase::buildTopMenuLowerPanel(void)
{
}


// Left Hand Menu
void WebPageBase::LHM_addLogo(const string & logo)
{
	m_lhm_logo = logo;
}

void WebPageBase::LHM_addMenuItem(const string & name, const string & link, const string & text)
{
	m_lhm_menu_items.emplace_front( MenuItem(name, link, text) ); //C++11
}


void WebPageBase::buildLeftMenu(void)
{
	HTMLBodyBasePtr lhm = m_page.add_span("left-hand-menu");
	//Logo
	HTMLBodyBasePtr lhmspanlogo = HTMLElementFactory::add_span(lhm, "logo");
	HTMLBodyBasePtr lhmlogo = HTMLElementFactory::add_image(lhmspanlogo, m_lhm_logo, PAGE_CDN(m_lhm_logo), m_lhm_logo);
	//Menu Items
	BOOST_FOREACH(MenuItem lhmitem, m_lhm_menu_items)
	{
		HTMLBodyBasePtr linkspan = HTMLElementFactory::add_span(lhm, "lmh-menu-item");
		HTMLBodyBasePtr link = HTMLElementFactory::add_link(linkspan, get<0>(lhmitem), get<1>(lhmitem), get<2>(lhmitem));
	}
}
// Right hand menu
void WebPageBase::RHM_addMenuItem(const string & name, const string & link, const string & text)
{
	m_rhm_menu_items.emplace_front( MenuItem(name, link, text) ); //C++11
}

void WebPageBase::buildRightMenu(void)
{
	HTMLBodyBasePtr rhm = m_page.add_span("right-hand-menu");
	BOOST_FOREACH(MenuItem rhmitem, m_rhm_menu_items)
	{
		HTMLBodyBasePtr rhmspan = HTMLElementFactory::add_span(rhm, "rhm-menu-item");
		HTMLBodyBasePtr link = HTMLElementFactory::add_link(rhmspan, get<0>(rhmitem), get<1>(rhmitem), get<2>(rhmitem));
	}
}

// Main page area
// Bottom menu
void WebPageBase::BM_addAffiliate(const string & logo, const string & link, const string & text)
{
	m_bm_affiliate.emplace_front( AffiliateItem(logo, link, text) ); //C++11
}

void WebPageBase::BM_addMenuItem(const string & name, const string & link, const string & text)
{
	m_bm_menu_items.emplace_front( MenuItem(name, link, text) ); //C++11
}

void WebPageBase::buildBottomMenu(void)
{
	HTMLBodyBasePtr bm = m_page.add_span("bottom-menu");
	//Affiliates
	BOOST_FOREACH(AffiliateItem bmaffiliate, m_bm_affiliate)
	{
		HTMLBodyBasePtr bmspan = HTMLElementFactory::add_span(bm, "affiliate");
		HTMLBodyBasePtr bmlink = HTMLElementFactory::add_link(bmspan, "affiliate", get<1>(bmaffiliate));
		HTMLBodyBasePtr bmimage = HTMLElementFactory::add_image(bmlink, get<0>(bmaffiliate), get<2>(bmaffiliate));
	}
	//Menu Items
	BOOST_FOREACH(MenuItem bmitem, m_bm_menu_items)
	{
		HTMLBodyBasePtr bmspan = HTMLElementFactory::add_span(bm, "rhm-menu-item");
		HTMLBodyBasePtr bmlink = HTMLElementFactory::add_link(bmspan, get<0>(bmitem), get<1>(bmitem), get<2>(bmitem));
	}
}

// Footer
void WebPageBase::buildFooter(void)
{
	HTMLBodyBasePtr footer = m_page.add_span("footer");
	HTMLBodyBasePtr foottextspan = HTMLElementFactory::add_span(footer, "text");
	//HTMLBodyBasePtr foottext = HTMLElementFactory::add_text(foottext, "Desgined Built and maintained by Eugene Web Designs");
	HTMLBodyBasePtr footlicencing = HTMLElementFactory::add_span(footer, "licencing");
	//HTMLBodyBasePtr footlicencingtxt = HTMLElementFactory::add_text(footlicencing, "Copyright Eugene Web Designs 2017");
}


// Displaying Functions
void WebPageBase::buildWebsite(void)
{
	// Building functions
	buildTopPanel();
	buildTopMenu();
	buildTopMenuLowerPanel();
	buildLeftMenu();
	buildRightMenu();
	buildBottomMenu();
	buildFooter();
}

void WebPageBase::displayWebsite(void)
{
	m_page.create_html();
	std::cout << m_page.get_html() << std::endl;
}

}

