#!/usr/bin/python
#Class to deal with the template for a CPP Implementation

#Import relative to executing python file
import cpp_template

from string import Template

class CPPImplementation (cpp_template.CPPTemplate):
	#Headers
	HPP_INCLUDE			=	'HEADER_INCLUDE'

	def __init__(self, output, dataDict):
		cpp_template.CPPTemplate.__init__(self, "page.cpp", output + ".cpp", dataDict)
		pass

	def __del__(self):
		cpp_template.CPPTemplate.__del__(self)

	def generateParameters(self):
		self.generateParametersTemplate()
		self.m_datamap[self.HPP_INCLUDE] = "#include \"" + self.m_datamap[self.CPP_CLASS] + ".hpp\"" #"#include "file_name"
