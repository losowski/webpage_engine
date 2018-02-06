#!/usr/bin/python
#Class to deal with the template for a Site Mapping header

#Import relative to executing python file
import base_template

from string import Template

class SiteHeader (base_template.BaseTemplate):
	def __init__(self, project, output, binaryName, cgiObjects ):
		base_template.BaseTemplate.__init__(self, "site.hpp", "cpp/lib"+project+"/" + output)
		pass

	def __del__(self):
		base_template.BaseTemplate.__del__(self)

	def populateDataMap(self):
		#Pass do nothing
		pass
