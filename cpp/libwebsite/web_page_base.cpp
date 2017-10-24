#include "web_page_base.hpp"
#include <iostream>

using namespace std;
using namespace html;

namespace web {

WebPageBase::WebPageBase(const string & title):
		m_page ( HTMLElementFactory::create_page("Hello World") )
{

}

WebPageBase::~WebPageBase(void)
{
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
	HTMLBodyBasePtr topmenu = m_page->add_span("top-menu");
	HTMLBodyBasePtr toppanel = HTMLElementFactory::add_span(topmenu, "top-panel");
	HTMLBodyBasePtr header = HTMLElementFactory::add_span(topmenu, "header");
	// Add the header
	HTMLElementFactory::add_h1(header, m_header);
	HTMLBodyBasePtr logo = HTMLElementFactory::add_span(topmenu, "logo");
	HTMLBodyBasePtr bottompanel = HTMLElementFactory::add_span(topmenu, "bottom-panel");
	HTMLBodyBasePtr timeplaceholder = HTMLElementFactory::add_span(topmenu, "time-placeholder");

}

void WebPageBase::displayWebsite(void)
{
	m_page->create_html();
	std::cout << m_page->get_html() << std::endl;
}

}
