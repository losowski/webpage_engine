#!/usr/bin/python
#Class to deal with the template for a Site Mapping header

#Import relative to executing python file
import cpp_code_template

from string import Template

class SiteHeader (cpp_code_template.CPPCodeTemplate):
	def __init__(self, project, className, baseClass, dbSchema, dbTableName, formDesign, variableList):
		cpp_code_template.CPPCodeTemplate.__init__(self, "site.hpp", project, "web_site.hpp", className, baseClass, dbSchema, dbTableName, formDesign, variableList)
		pass

	def __del__(self):
		cpp_code_template.CPPCodeTemplate.__del__(self)

	def populateDataMap(self):
		#Pass do nothing
		pass
