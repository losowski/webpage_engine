#include "html_body.hpp"

using namespace std;

namespace html {

HTMLBodyBase::HTMLBodyBase(const string & type, const string & name) :
	m_type(type), m_name(name)
{
}

HTMLBodyBase::~HTMLBodyBase(void)
{
}


}
