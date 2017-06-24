#include "html_form_input.hpp"

#include <string>

using namespace std;

namespace html {
namespace form {

HTMLFormInput::HTMLFormInput()
{
}

HTMLFormInput::HTMLFormInput(const string & field_name, const string & label, const string & value)
{
}

HTMLFormInput::~HTMLFormInput()
{
}

string HTMLFormInput::get_form_input(void)
{
	return m_html_form_input;
}


}
}

