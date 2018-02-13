#!/usr/bin/python
#Class to deal with the template for a Site Mapping Implementation

#Import relative to executing python file
import base_template

from string import Template

class BinImplementation (base_template.BaseTemplate):

	def __init__(self, project, output, binaryName, cgiObjects ):
		base_template.BaseTemplate.__init__(self, "bin_site.cpp", "cpp/bin"+project+"/" + output)
		self.binaryName = binaryName
		self.cgiObjects = cgiObjects
		self.populateDataMap()
		pass

	def __del__(self):
		base_template.BaseTemplate.__del__(self)

	def populateDataMap(self):
		#Pass do nothing
		CGI_DEFAULT_PAGE
		pass

	def populateDataMap(self):
		self.dataMap = {}

