#include "html_header_meta.hpp"

using namespace std;

namespace html {
namespace header {

const MetaType HTMLHeaderMeta::HTML_META_DESCRIPTION("description");
const MetaType HTMLHeaderMeta::HTML_META_KEYWORDS("keywords");
const MetaType HTMLHeaderMeta::HTML_META_AUTHOR("author");

HTMLHeaderMeta::HTMLHeaderMeta(const HTHMLHeaderMetaType & tag, const string & content)):
	HTMLHeader(tag),
	m_meta_content(content)
{
}

HTMLHeaderMeta::~HTMLHeaderMeta(void)
{
}

void HTMLHeaderMeta::create_header(void)
{
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	m_html_header = "<meta name=\"" + m_resource_url + "\" content=\"" + m_meta_content + "\"></meta>\n";
}

}
}

