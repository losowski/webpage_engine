#include "web_page_base.hpp"
#include "html_element_factory.hpp"


#include <iostream>

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

void WebPageBase::setPageTitle(const string & header)
{
	m_header = header;
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


// Building functions
void WebPageBase::buildTopPanel(void)
{
	HTMLBodyBasePtr toppanel = m_page.add_span("top-panel");
}

void WebPageBase::buildTopMenu(void)
{
	HTMLBodyBasePtr topmenu = m_page.add_span("top-menu");
	HTMLBodyBasePtr topmenulogo = HTMLElementFactory::add_span(topmenu, "logo");
	HTMLBodyBasePtr header = HTMLElementFactory::add_span(topmenu, "header-title");
	HTMLElementFactory::add_h1(header, "header-title", m_header);
}

void WebPageBase::buildLeftMenu(void)
{
	HTMLBodyBasePtr lefthandmenu = m_page.add_span("left-hand-menu");
	HTMLBodyBasePtr lefthandmenulogo = HTMLElementFactory::add_span(lefthandmenu, "logo");
}

void WebPageBase::buildRightMenu(void)
{
	HTMLBodyBasePtr righthandmenu = m_page.add_span("right-hand-menu");
}

void WebPageBase::buildBottomMenu(void)
{
	HTMLBodyBasePtr bottommenu = m_page.add_span("bottom-menu");
}

void WebPageBase::buildFooter(void)
{
	HTMLBodyBasePtr footer = m_page.add_span("footer");
}

void WebPageBase::buildFooterPanel(void)
{
	HTMLBodyBasePtr footerpanel = m_page.add_span("footer-panel");
}


}

