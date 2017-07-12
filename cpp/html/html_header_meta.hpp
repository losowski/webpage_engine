#ifndef HTML_HEADER_STYLE_HPP
#define HTML_HEADER_STYLE_HPP

#include "html_header.hpp"
#include <string>

using namespace std;

namespace html {
namespace header {

typedef string			HTHMLHeaderMetaType;

class HTMLHeaderMeta: public html::header::HTMLHeader {
	public:
		HTMLHeaderMeta(const HTHMLHeaderMetaType & tag, const string & content);
		~HTMLHeaderMeta(void);
	public:
		static const MetaType HTML_META_DESCRIPTION;
		static const MetaType HTML_META_KEYWORDS;
		static const MetaType HTML_META_AUTHOR;
	public:
		void create_header(void);
	private:
		string				m_meta_content;
};
}
}
#endif //HTML_HEADER_STYLE_HPP
