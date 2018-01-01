#!/usr/bin/python
# Autogenerate script to build the CGI classes for a CGI application

from build_page_queries import cpp_template
from build_page_queries import cpp_header
from build_page_queries import cpp_implementation


def main():
	# my code here
	print "Autogenerate CGI classes"
#	data =	{cpp_template.CPP_CLASS : "demo_page",
	data =	{	cpp_template.CPPTemplate.CPP_CLASS : "demo_page",
				cpp_template.CPPTemplate.VARIABLE_LIST: ['id', 'forename', 'happiness', 'created_date'],
			}
	hdr = cpp_header.CPPHeader("demo_page", data)
	hdr.loadTemplate()
	hdr.generateParameters()
	hdr.generateSourceCode()

if __name__ == "__main__":
	main()
