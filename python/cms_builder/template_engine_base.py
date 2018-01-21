#!/usr/bin/python
#Class to deal with the template for a CPP template

from build_templates import cgi_files
from build_templates import cpp_makefile

class TemplateEngineBase:
	TEMPLATE_BINARY	=	'TEMPLATE_BINARY'
	TEMPLATE_FILES	=	'TEMPLATE_FILES'
	def __init__(self):
		self.database = dict()

	def __del__(self):
		pass

	def getData(self):
		pass

	def buildTemplates(self):
		print "Autogenerate CGI classes"
		for filename in self.database:
			#CGI File Generation
			cgi = cgi_files.CGIFiles(filename, data)
			cgi.loadTemplate()
			cgi.generateParameters()
			cgi.generateSourceCode()
			#Postgresql Stored Procedure
		#CPP Makefile
		make = cpp_makefile.CPPMakefile("makefile", self.database[self.TEMPLATE_FILES], self.database[self.TEMPLATE_BINARY] )
		make.loadTemplate()
		make.generateParameters()
		make.generateSourceCode()

