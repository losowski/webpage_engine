#include "web_page_base.hpp"
#include "html_element_factory.hpp"


#include <iostream>
#include <boost/foreach.hpp>

using namespace std;
using namespace html;

namespace web {

#define PAGE_CDN_IMAGE(image){ m_cdn + m_media_path + image}

WebPageBase::WebPageBase(const string & title):
		WebPageBaseCGI(),
		m_id ("NULL"),
		m_cdn ("//localhost/"),
		m_page ( title ),
		m_dbconnection(NULL)
{
}

WebPageBase::WebPageBase(const string & title, cgicc::Cgicc * m_cgi):
		WebPageBaseCGI(m_cgi),
		m_id ("NULL"),
		m_cdn ("//localhost/"),
		m_page ( title ),
		m_dbconnection(NULL)
{
}

WebPageBase::~WebPageBase(void)
{
	//Hopefully Clean the m_dbconnection object
	if (this->m_dbconnection != NULL)
	{
		delete this->m_dbconnection;
	}
}
//Public:
void WebPageBase::connectDB(const string & connection)
{
	try
	{
		// Connect to the database
		m_dbconnection = new pqxx::connection(connection);
	}
	catch (const pqxx::sql_error &e)
	{
		std::cerr << "SQL error: " << e.what() << std::endl;
		std::cerr << "Query was: " << e.query() << std::endl;
		exit(EXIT_FAILURE);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
}

// CGI and Database
void WebPageBase::actionData(void)
{
	/*
		1)	Parse the QueryString
			-	Primary Key
			-	Action
				- For forms this is a hidden input field
		2) Identify key for action
			UNSET	- Skip to step 4
			SET		- Perform specified action (See step 3)
		3) Perform the action
			Database:	UPDATE / INSERT / DELETE / NONE
		4) Get the data to display
			Database:	SELECT
		5) Display the data
			- Build the webpage
	*/
	try
	{
		// Step 1: Processing the QueryString
		// 	- Done as part of initialisation of m_cgi

		if (m_cgi != NULL)
		{
			actionDataCGI();
		}
		// Action the SQL
		if (m_dbconnection != NULL)
		{
			// Step 2: Identify key for action
			// FIXME: This needs to take into account the form input to deliver a true KEY value.
			if (false == m_cgikey.empty())
			{
				//Get a transaction
				pqxx::work txn(*m_dbconnection);
				 // Step 3: Perform the action
				actionDataUpdateSQL(txn, m_cgikey);
			}
			//Check the Primary Key is set
			if (true == m_has_primary_key)
			{
				//Get a transaction
				pqxx::work txn(*m_dbconnection);
				// Step 4: Get the data to display
				actionDataSelectSQL(txn);
			}
		}
	}
	catch (const pqxx::sql_error &e)
	{
		//TODO: Add redirect to a static webpage to say "Technical Difficulties"
		m_page.clear_page();
		m_page.add_title("Whoops! Something went wrong:/");
		m_page.add_h1("Whoops! Something went wrong:/");
		//Report what went wrong
		std::cerr << "actionData SQL error: " << e.what() << std::endl;
		std::cerr << "actionData Query was: " << e.query() << std::endl;
		displayWebsite();
		exit(EXIT_FAILURE);
	}
	catch (const std::exception &e)
	{
		//TODO: Add redirect to a static webpage - 404?
		std::cerr << "actionData Error: " << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
}

//Build the page
void WebPageBase::setCDN(const string & cdn)
{
	m_cdn = "//" + cdn + "/";
}

void WebPageBase::setMediaPath(const string & path)
{
	m_media_path = path + "/";
}

void WebPageBase::setJavascriptPath(const string & path)
{
	m_javascript_path = path + "/";
}

void WebPageBase::setCSSPath(const string & path)
{
	m_css_path = path + "/";
}


//Header Functions
//TODO: Include SEO functions (meta tag)
void WebPageBase::addJavascript(const string & filename)
{
	m_page.add_script(m_cdn + m_javascript_path + filename);
}

void WebPageBase::addCSS(const string & filename)
{
	m_page.add_style(m_cdn + m_css_path + filename);
}

// Top panel
void WebPageBase::buildTopPanel(void)
{
	HTMLBodyBasePtr toppanel = m_page.add_div("top-panel");
}

// Top Menu
void WebPageBase::TM_addLogo(const string & logo)
{
	m_tm_header_logo = PAGE_CDN_IMAGE(logo);
}

void WebPageBase::TM_setPageTitle(const string & header)
{
	m_tm_header = header;
}

void WebPageBase::buildTopMenu(void)
{
	//Style
	addCSS("top-menu");
	//Scripts
	//Menu
	HTMLBodyBasePtr tm = m_page.add_div("top-menu");
	//Logo
	HTMLBodyBasePtr tmspanlogo = HTMLElementFactory::add_div(tm, "logo");
	HTMLBodyBasePtr tmlogo = HTMLElementFactory::add_image(tmspanlogo, "top-menu-logo", m_tm_header_logo);
	//Title
	HTMLBodyBasePtr tmheader = HTMLElementFactory::add_div(tm, "title");
	HTMLElementFactory::add_h1(tmheader, "header-title", m_tm_header);
}
// Top Menu Lower Panel
void WebPageBase::buildTopMenuLowerPanel(void)
{
}


// Left Hand Menu
void WebPageBase::LHM_addLogo(const string & logo)
{
	m_lhm_logo = PAGE_CDN_IMAGE(logo);
}

void WebPageBase::LHM_addMenuItem(const string & name, const string & link, const string & text)
{
	m_lhm_menu_items.emplace_front( MenuItem(name, link, text) ); //C++11
}


void WebPageBase::buildLeftMenu(void)
{
	//Style
	addCSS("left-hand-menu");
	//Scripts
	//Menu
	HTMLBodyBasePtr lhm = m_page.add_div("left-hand-menu");
	//Logo
	HTMLBodyBasePtr lhmspanlogo = HTMLElementFactory::add_div(lhm, "logo");
	HTMLBodyBasePtr lhmlogo = HTMLElementFactory::add_image(lhmspanlogo, "left-hand-menu-logo", m_lhm_logo);
	//Menu Items
	BOOST_FOREACH(MenuItem lhmitem, m_lhm_menu_items)
	{
		HTMLBodyBasePtr linkspan = HTMLElementFactory::add_div(lhm, "lmh-menu-item");
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
	//Style
	addCSS("right-hand-menu");
	//Scripts
	HTMLBodyBasePtr rhm = m_page.add_div("right-hand-menu");
	BOOST_FOREACH(MenuItem rhmitem, m_rhm_menu_items)
	{
		HTMLBodyBasePtr rhmspan = HTMLElementFactory::add_div(rhm, "rhm-menu-item");
		HTMLBodyBasePtr link = HTMLElementFactory::add_link(rhmspan, get<0>(rhmitem), get<1>(rhmitem), get<2>(rhmitem));
	}
}

// Main page area
void WebPageBase::buildMainMenu(void)
{
	//Do Nothing. Override for implementation
}

// Bottom menu
void WebPageBase::BM_addAffiliate(const string & logo, const string & link, const string & text)
{
	m_bm_affiliate.emplace_front( AffiliateItem(logo, link, text) ); //C++11
}

void WebPageBase::BM_addMenuItem(const string & name, const string & link, const string & text)
{
	m_bm_menu_items.emplace_front( MenuItem(name, link, text) ); //C++11
}

//Generic Menus
void WebPageBase::addMenuItem(const string & name, const string & link, const string & text)
{
	LHM_addMenuItem(name, link, text);
	RHM_addMenuItem(name, link, text);
	BM_addMenuItem(name, link, text);
}


//Build menus
void WebPageBase::buildBottomMenu(void)
{
	//Style
	addCSS("bottom-menu");
	//Scripts
	HTMLBodyBasePtr bm = m_page.add_div("bottom-menu");
	//Affiliates
	BOOST_FOREACH(AffiliateItem bmaffiliate, m_bm_affiliate)
	{
		HTMLBodyBasePtr bmspan = HTMLElementFactory::add_div(bm, "affiliate");
		HTMLBodyBasePtr bmlink = HTMLElementFactory::add_link(bmspan, "affiliate", get<1>(bmaffiliate));
		HTMLBodyBasePtr bmimage = HTMLElementFactory::add_image(bmlink, get<0>(bmaffiliate), get<2>(bmaffiliate));
	}
	//Menu Items
	HTMLBodyBasePtr bmspan = HTMLElementFactory::add_div(bm, "bottom-menu-item");
	BOOST_FOREACH(MenuItem bmitem, m_bm_menu_items)
	{
		HTMLBodyBasePtr bmlink = HTMLElementFactory::add_link(bmspan, get<0>(bmitem), get<1>(bmitem), get<2>(bmitem));
	}
}

// Footer
void WebPageBase::buildFooter(void)
{
	//Style
	addCSS("footer");
	//Scripts
	HTMLBodyBasePtr footer = m_page.add_div("footer");
	HTMLBodyBasePtr foottextspan = HTMLElementFactory::add_div(footer, "footer-text");
	HTMLBodyBasePtr foottext = HTMLElementFactory::add_text(foottextspan, "Desgined Built and maintained by Eugene Web Designs");
	HTMLBodyBasePtr footlicencing = HTMLElementFactory::add_div(footer, "licencing");
	HTMLBodyBasePtr footlicencingtxt = HTMLElementFactory::add_text(footlicencing, "Copyright Eugene Web Designs 2017");
}


// Displaying Functions
void WebPageBase::buildWebsite(void)
{
	// Building functions
	buildTopPanel();
	buildTopMenu();
	buildTopMenuLowerPanel();
	buildLeftMenu();
	buildMainMenu();
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

