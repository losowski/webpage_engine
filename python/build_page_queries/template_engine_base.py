#!/usr/bin/python
#Class to deal with the template for a CPP template

from build_templates import cpp_template
from build_templates import cpp_header
from build_templates import cpp_implementation

class TemplateEngineBase:
	def __init__(self):
		self.database = dict()

	def __del__(self):
		pass

	def getClasses(self):
		pass

	def getClassFields(self, className):
		pass

	def buildTemplates(self):
		print "Autogenerate CGI classes"
		for filename, data in self.database.iteritems():
			hdr = cpp_header.CPPHeader(filename, data)
			hdr.loadTemplate()
			hdr.generateParameters()
			hdr.generateSourceCode()

			impl = cpp_implementation.CPPImplementation(filename, data)
			impl.loadTemplate()
			impl.generateParameters()
			impl.generateSourceCode()

