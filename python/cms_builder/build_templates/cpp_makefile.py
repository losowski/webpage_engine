#!/usr/bin/python
#Class to deal with the template for a CPP Implementation

#Import relative to executing python file
import cpp_template

from string import Template

class CPPMakefile (cpp_template.CPPTemplate):
	#Headers
	MAKEFILE_FILES			=	'MAKEFILE_FILES'
	MAKEFILE_PROGRAM_NAME	=	'MAKEFILE_PROGRAM_NAME'

	def __init__(self, output, dataDict, executable):
		cpp_template.CPPTemplate.__init__(self, "makefile", output, dataDict)
		self.executable = executable
		pass

	def __del__(self):
		cpp_template.CPPTemplate.__del__(self)

	def extendSpecificParameters(self):
		#m_datamap.keys() must be first
		self.m_datamap[self.MAKEFILE_FILES] = ' '.join(self.m_datamap.keys())
		#Executable MUST be after (order sensitive)
		self.m_datamap[self.MAKEFILE_PROGRAM_NAME] = self.executable



