#!/usr/bin/python
# Autogenerate script to build the CGI classes for a CGI application

from build_page_queries import cpp_template
from build_page_queries import cpp_header
from build_page_queries import cpp_implementation


def main():
	# my code here
	print "Autogenerate CGI classes"
#	data =	{cpp_template.CPP_CLASS : "demo_page",
	database =	{	"demo_page" :	{	cpp_template.CPPTemplate.CPP_CLASS : "demo_page",
										cpp_template.CPPTemplate.VARIABLE_LIST: ['id', 'forename', 'happiness', 'created_date'],
									}
				}

	for filename, data in database.iteritems():
		hdr = cpp_header.CPPHeader(filename, data)
		hdr.loadTemplate()
		hdr.generateParameters()
		hdr.generateSourceCode()

		impl = cpp_implementation.CPPImplementation(filename, data)
		impl.loadTemplate()
		impl.generateParameters()
		impl.generateSourceCode()

if __name__ == "__main__":
	main()
