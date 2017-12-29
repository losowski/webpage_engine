#include "web_page_base_cgi.hpp"

using namespace std;

namespace web {

WebPageBaseCGI::WebPageBaseCGI(void):
		m_has_primary_key(false),
		m_cgi	(NULL)
{
}

WebPageBaseCGI::~WebPageBaseCGI(void)
{
	//Hopefully Clean the m_cgi object
	if (this->m_cgi != NULL)
	{
		delete this->m_cgi;
	}
}

//public:
void WebPageBaseCGI::parseCGI(void)
{
	try
	{
		//Get the CGI parameters
		m_cgi = new cgicc::Cgicc;
		//Process the query string
		process_getCGIEnvironment();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
}

//protected:
void WebPageBaseCGI::PrimaryKeySet(void)
{
	m_has_primary_key = true;
}

void WebPageBaseCGI::parseCGIKey(void)
{
	parseCGIParameter(m_cgikey, "key");
}

void WebPageBaseCGI::parseCGIPrimaryKey(string & variable, const string & querykey)
{
	// Setting the pk value
	cgicc::form_iterator itpk = m_cgi->getElement(querykey);
	if (itpk != m_cgi->getElements().end() && (itpk->getValue().empty() == false))
	{
		variable = itpk->getValue();
		PrimaryKeySet(); // Special Addition
	}
	if (true == variable.empty())
	{
		//Get QueryString - Essential for correct behaviour
		variable = getCGIEnvironment(querykey);
	}
}

void WebPageBaseCGI::parseCGIParameter(string & variable, const string & querykey)
{
	cgicc::form_iterator itforename = m_cgi->getElement(querykey);
	if (itforename != m_cgi->getElements().end() && itforename->getValue().empty() == false)
	{
		variable = itforename->getValue();
	}
	if (true == variable.empty())
	{
		//Get data from query string QueryString
		variable = getCGIEnvironment(querykey);
	}
}

string WebPageBaseCGI::getCGIEnvironment(const string & key)
{
	return m_cgi_environment[key];
}


//private:
void WebPageBaseCGI::parse_getCGIEnvironment(const string & kvp)
{
	// Iterate over elements in vector to get instances of "="
	std::size_t found = kvp.find_first_of("=");
	string key (kvp, 0, found);
	string value (kvp, found +1, (kvp.size()-found-1));
	//Insert the value
	m_cgi_environment[key] = value;
}

void WebPageBaseCGI::process_getCGIEnvironment(void)
{
	// CGICC get the environment
	string query = m_cgi->getEnvironment().getQueryString();
	//Iterate over query to get all instances of "&"
	std::size_t unfound = 0;
	std::size_t found = query.find_first_of("&");
	while (found != std::string::npos)
	{
		string kvp(query, unfound, found);
		parse_getCGIEnvironment(kvp);
		//Set unfound properly
		unfound = found+1;
		//Get next iteration
		found = query.find_first_of("&",found+2);
	}
	//Final round - found == std::string::npos
	string kvp(query, unfound, query.size()-unfound);
	parse_getCGIEnvironment(kvp);
}


}

