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
	/*
	 *	Top Menu
	 */
	HTMLBodyBasePtr topmenu = m_page.add_span("top-menu");
	HTMLBodyBasePtr toppanel = HTMLElementFactory::add_span(topmenu, "top-panel");
	HTMLBodyBasePtr header = HTMLElementFactory::add_span(topmenu, "header");
	// Add the header
	HTMLElementFactory::add_h1(header, "header", m_header);
	HTMLBodyBasePtr logo = HTMLElementFactory::add_span(topmenu, "logo");
	HTMLBodyBasePtr bottompanel = HTMLElementFactory::add_span(topmenu, "bottom-panel");
	HTMLBodyBasePtr timeplaceholder = HTMLElementFactory::add_span(topmenu, "time-placeholder");

}

void WebPageBase::displayWebsite(void)
{
	m_page.create_html();
	std::cout << m_page.get_html() << std::endl;
}

}
