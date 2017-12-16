#include "web_page_base_cgi.hpp"

using namespace std;

namespace web {

WebPageBaseCGI::WebPageBaseCGI(void):
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

void WebPageBaseCGI::parse_getCGIEnvironment(const string & kvp)
{
	// Iterate over elements in vector to get instances of "="
	std::size_t found = kvp.find_first_of("=");
	string key (kvp, 0, found);
	string value (kvp, found +1, std::string::npos);
	//Insert the value
	m_cgi_environment[key] = value;
}

string WebPageBaseCGI::getCGIEnvironment(const string & key)
{
	return m_cgi_environment[key];
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
		unfound = found;
		//Get next iteration
		std::size_t found = query.find_first_of("&",found+1);
	}
	//Final round
	string kvp(query, unfound, found);
	parse_getCGIEnvironment(kvp);
}


}

