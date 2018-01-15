#!/usr/bin/python
#Class to deal with the template for a CPP Implementation

#Import relative to executing python file
import cpp_template

from string import Template

class CPPMakefile (cpp_template.CPPTemplate):
	#Headers
	MAKEFILE_FILES			=	'MAKEFILE_FILES'
	MAKEFILE_PROGRAM_NAME	=	'MAKEFILE_PROGRAM_NAME'

	def __init__(self, output, dataDict):
		cpp_template.CPPTemplate.__init__(self, "makefile", output, dataDict)
		pass

	def __del__(self):
		cpp_template.CPPTemplate.__del__(self)

	def extendSpecificParameters(self):
		self.m_datamap[self.MAKEFILE_FILES] = None
		self.m_datamap[self.MAKEFILE_PROGRAM_NAME] = None

