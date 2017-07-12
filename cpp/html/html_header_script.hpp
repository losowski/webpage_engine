#ifndef HTML_HEADER_SCRIPT_HPP
#define HTML_HEADER_SCRIPT_HPP

#include "html_header.hpp"
#include <string>

using namespace std;

namespace html {
namespace header {

class HTMLHeaderScript: public html::header::HTMLHeader {
	public:
		HTMLHeaderScript(const string & url);
		~HTMLHeaderScript(void);
	public:
		void create_header(void);
	protected:
		string								m_resource_url;
		string								m_html_header;
};
}
}
#endif //HTML_HEADER_SCRIPT_HPP
