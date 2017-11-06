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

void WebPageBase::set_cdn(const string & cdn)
{
	m_cdn = "//" + cdn + "/";
}

void WebPageBase::set_media_path(const string & path)
{
	m_media_path = path;
}

void WebPageBase::setHeader(const string & header)
{
	m_header = header;
}


void WebPageBase::buildWebsite(void)
{
	/* Top panel */
	HTMLBodyBasePtr toppanel = m_page.add_span("top-panel");
	/* Top Menu */
	HTMLBodyBasePtr topmenu = m_page.add_span("top-menu");
	HTMLBodyBasePtr topmenulogo = HTMLElementFactory::add_span(topmenu, "logo");
	HTMLBodyBasePtr header = HTMLElementFactory::add_span(topmenu, "header-title");
	HTMLElementFactory::add_h1(header, "header-title", m_header);
	/* Left Hand Menu */
	HTMLBodyBasePtr lefthandmenu = m_page.add_span("left-hand-menu");
	HTMLBodyBasePtr lefthandmenulogo = HTMLElementFactory::add_span(lefthandmenu, "logo");
	/* Right Hand Menu */
	HTMLBodyBasePtr righthandmenu = m_page.add_span("right-hand-menu");
	/* Bottom Menu */
	HTMLBodyBasePtr bottommenu = m_page.add_span("bottom-menu");
	/* Footer */
	HTMLBodyBasePtr footer = m_page.add_span("footer");
	/* Footer Panel */
	HTMLBodyBasePtr footerpanel = m_page.add_span("footer-panel");
}

void WebPageBase::displayWebsite(void)
{
	m_page.create_html();
	std::cout << m_page.get_html() << std::endl;
}

}

