#include "web_page_base.hpp"
#include "html_element_factory.hpp"


#include <iostream>
#include <boost/foreach.hpp>

using namespace std;
using namespace html;

namespace web {

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
void WebPageBase::H_addJavascript(const string & filename)
{
	m_page.add_script(m_javascript_path + filename);
}

void WebPageBase::H_addCSS(const string & filename)
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
	m_tm_header_logo = m_cdn + m_media_path + logo;
}

void WebPageBase::TM_setPageTitle(const string & header)
{
	m_tm_header = header;
}

void WebPageBase::buildTopMenu(void)
{
	HTMLBodyBasePtr tm = m_page.add_span("top-menu");
	HTMLBodyBasePtr tmspanlogo = HTMLElementFactory::add_span(tm, "logo");
	HTMLBodyBasePtr tmlogo = HTMLElementFactory::add_image(tmspanlogo, m_tm_header_logo, m_tm_header_logo);
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
	m_lhm_logo = m_cdn + m_media_path + logo;
}

void WebPageBase::LHM_addMenuItem(const string & link, const string & text)
{
	m_lhm_menu_items.emplace_front( LHMItem(link, text) ); //C++11
}


void WebPageBase::buildLeftMenu(void)
{
	HTMLBodyBasePtr lhm = m_page.add_span("left-hand-menu");
	HTMLBodyBasePtr lhmspanlogo = HTMLElementFactory::add_span(lhm, "logo");
	HTMLBodyBasePtr lhmlogo = HTMLElementFactory::add_image(lhmspanlogo, m_lhm_logo, m_lhm_logo);
	BOOST_FOREACH(LHMItem lhmmenuitem, m_lhm_menu_items)
	{
		HTMLBodyBasePtr linkspan = HTMLElementFactory::add_span(lhm, "lmh-menu-item");
		HTMLBodyBasePtr link = HTMLElementFactory::add_link(linkspan, get<0>(lhmmenuitem), get<1>(lhmmenuitem));
	}
}
// Right hand menu
void WebPageBase::buildRightMenu(void)
{
	HTMLBodyBasePtr righthandmenu = m_page.add_span("right-hand-menu");
}

// Main page area
// Bottom menu
void WebPageBase::buildBottomMenu(void)
{
	HTMLBodyBasePtr bottommenu = m_page.add_span("bottom-menu");
}

// Footer
void WebPageBase::buildFooter(void)
{
	HTMLBodyBasePtr footer = m_page.add_span("footer");
}

// Footer Panel
void WebPageBase::buildFooterPanel(void)
{
	HTMLBodyBasePtr footerpanel = m_page.add_span("footer-panel");
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
	buildFooterPanel();
}

void WebPageBase::displayWebsite(void)
{
	m_page.create_html();
	std::cout << m_page.get_html() << std::endl;
}

}

