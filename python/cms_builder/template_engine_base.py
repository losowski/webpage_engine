#!/usr/bin/python
#Class to deal with the template for a CPP template

from build_templates import cgi_files
from build_templates import cpp_makefile
from build_templates import site_header
from build_templates import site_implementation
from build_templates import bin_makefile
from build_templates import bin_implementation

class TemplateEngineBase:
	TEMPLATE_BINARY	=	'TEMPLATE_BINARY'
	TEMPLATE_FILES	=	'TEMPLATE_FILES'
	def __init__(self):
		self.database = dict()
		self.cgiBinaryName	=	"web"
		self.databaseName	=	"cms"
		self.databaseUser	=	"cms"

	def __del__(self):
		pass

	def getData(self):
		pass

	def buildTemplates(self):
		print "Autogenerate CGI classes"
		for cgi in self.cgiObjects:
			#CGI File Generation
			cgi.initialize(self.databaseName, self.databaseUser)
			cgi.buildCGIComponents()
				#CPP File
				#HPP File
				#Postgresql Stored Procedure
				#Postgresql Create Database
		#Site Header
		sHeader = site_header.SiteHeader(self.cgiBinaryName, "web_site_cms.hpp", self.cgiBinaryName, self.cgiObjects)
		sHeader.loadTemplate()
		sHeader.generateParameters()
		sHeader.generateSourceCode()
		#Site Implementation
		sImplementation = site_implementation.SiteImplementation(self.cgiBinaryName, "web_site_cms.cpp", self.cgiBinaryName, self.cgiObjects)
		sImplementation.loadTemplate()
		sImplementation.generateParameters()
		sImplementation.generateSourceCode()
		#CPP Makefile
		make = cpp_makefile.CPPMakefile(self.cgiBinaryName, "makefile", self.cgiBinaryName, self.cgiObjects)
		make.loadTemplate()
		make.generateParameters()
		make.generateSourceCode()
		### BINARY EXECUTABLE ###
		#Binary Implementation
		binimpl = bin_implementation.BinImplementation(self.cgiBinaryName, "web.cpp", self.cgiBinaryName, self.cgiObjects)
		binimpl.loadTemplate()
		binimpl.generateParameters()
		binimpl.generateSourceCode()
		#Binary Makefile
		binmake = bin_makefile.BinMakefile(self.cgiBinaryName, "makefile", self.cgiBinaryName, self.cgiObjects)
		binmake.loadTemplate()
		binmake.generateParameters()
		binmake.generateSourceCode()

