#!/usr/bin/python
#Class to deal with the template for a CPP template

from build_templates import cpp_template
from build_templates import cpp_header
from build_templates import cpp_implementation
from build_templates import cpp_makefile

class TemplateEngineBase:
	def __init__(self):
		self.database = dict()

	def __del__(self):
		pass

	def getData(self):
		pass

	def buildTemplates(self):
		print "Autogenerate CGI classes"
		for filename, data in self.database.iteritems():
			#CPP Header file
			hdr = cpp_header.CPPHeader(filename, data)
			hdr.loadTemplate()
			hdr.generateParameters()
			hdr.generateSourceCode()
			#CPP Implementation file
			impl = cpp_implementation.CPPImplementation(filename, data)
			impl.loadTemplate()
			impl.generateParameters()
			impl.generateSourceCode()
			#Postgresql Stored Procedure
		#CPP Makefile
		make = cpp_makefile.CPPMakefile("makefile", data)
		make.loadTemplate()
		make.generateParameters()
		make.generateSourceCode()

