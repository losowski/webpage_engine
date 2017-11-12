#include "html_text.hpp"

using namespace std;

namespace html {

HTMLText::HTMLText(const string & name, const string & text):
	HTMLTextBase("p", name, text)
{
}

HTMLText::~HTMLText(void)
{
}

}
