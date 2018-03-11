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
		WebPageBaseCGI(cgicc::Cgicc * m_cgi);
		~WebPageBaseCGI(void);
	public:
		void parseCGI(void);
	protected:
		string getCGIEnvironment(const string & key);
		//virtual void actionDataCGI(void) = 0; // In derived class
		void PrimaryKeySet(void);
		void parseCGIKey(void);
		void parseCGIPage(void);
		void parseCGIPrimaryKey(string & variable, const string & querykey);
		void parseCGIParameter(string & variable, const string & querykey);
	private:
		void process_getCGIEnvironment(void);
		void parse_getCGIEnvironment(const string & kvp);
	protected:
		bool						m_has_primary_key;
		string						m_cgikey;
		string						m_cgipage;
		//CGI Objects
		bool						m_owns_cgi;
		cgicc::Cgicc *				m_cgi;
		map < string, string >		m_cgi_environment;
};
}
#endif //WEB_PAGE_BASE_HPP
