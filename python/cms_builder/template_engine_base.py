#!/usr/bin/python
#Class to deal with the template for a CPP template

from build_templates import cgi_files
from build_templates import cpp_makefile

class TemplateEngineBase:
	TEMPLATE_BINARY	=	'TEMPLATE_BINARY'
	TEMPLATE_FILES	=	'TEMPLATE_FILES'
	def __init__(self):
		self.database = dict()
		self.cgiBinaryName	=	"webcms"

	def __del__(self):
		pass

	def getData(self):
		pass

	def buildTemplates(self):
		print "Autogenerate CGI classes"
		for cgi in self.cgiObjects:
			#CGI File Generation
			cgi.initialize()
			cgi.buildCGIComponents()
				#CPP File
				#HPP File
				#Postgresql Stored Procedure
				#Postgresql Create Database
		#CPP Makefile
		make = cpp_makefile.CPPMakefile(self.cgiBinaryName, "makefile", self.cgiBinaryName, self.cgiObjects)
		make.loadTemplate()
		make.generateParameters()
		make.generateSourceCode()

