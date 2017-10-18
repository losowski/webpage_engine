#ifndef HTML_ELEMENT_HPP
#define HTML_ELEMENT_HPP

using namespace std;

namespace html {

class HTMLElementFactor : public html::HTMLElementFactoryBase
{
	public:
		HTMLElementFactoryBase(void);
		~HTMLElementFactoryBase(void);
	public:
		/* Form */
		static HTMLFormPtr add_form(HTMLBodyElementPtr element, const string & name, const string & action);

};
}
#endif //HTML_ELEMENT_HPP
