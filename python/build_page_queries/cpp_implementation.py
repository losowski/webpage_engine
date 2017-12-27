#!/usr/bin/python
#Class to deal with the template for a CPP Implementation

import cpp_template

class CPPImplementation (cpp_template.CPPTemplate):
	def __init__(self, output, dataDict):
		cpp_template.CPPTemplate.__init__(self, "page.hpp", output, dataDict)
		pass

	def __del__(self):
		cpp_template.CPPTemplate.__del__(self)
