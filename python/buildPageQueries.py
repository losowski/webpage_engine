#!/usr/bin/python
# Autogenerate script to build the CGI classes for a CGI application

from build_page_queries import cpp_header

def main():
	# my code here
	print "Autogenerate CGI classes"
	data = dict()
	hdr = cpp_header.CPPHeader("demo_page", data)
	hdr.loadTemplate()
	hdr.generateParameters()
	hdr.generateSourceCode()

if __name__ == "__main__":
	main()
