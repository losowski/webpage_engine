#ifndef WEB_PAGE_BASE_CGI_HPP
#define WEB_PAGE_BASE_CGI_HPP

#include <map>

//CGI
#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"



using namespace std;

namespace web {

class WebPageBaseCGI
{
	public:
		WebPageBaseCGI(void);
		~WebPageBaseCGI(void);
	public:
		void parseCGI(void);
		string getCGIEnvironment(const string & key);
		//virtual void actionDataCGI(void) = 0; // In derived class
	private:
		void process_getCGIEnvironment(void);
		void parse_getCGIEnvironment(const string & kvp);
	protected:
		string						m_cgikey;
		//CGI Objects
		cgicc::Cgicc *				m_cgi;
		map < string, string >		m_cgi_environment;
};
}
#endif //WEB_PAGE_BASE_HPP
