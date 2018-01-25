#!/usr/bin/python
#Class to deal with the template for a CPP Implementation

#Import relative to executing python file
import base_template

from string import Template

class SQLCreateTable (base_template.BaseTemplate):
	#Headers
	MAKEFILE_FILES			=	'MAKEFILE_FILES'
	MAKEFILE_PROGRAM_NAME	=	'MAKEFILE_PROGRAM_NAME'

	def __init__(self, output, binaryName, cgiObjects ):
		base_template.BaseTemplate.__init__(self, "makefile", output)
		self.binaryName = binaryName
		self.cgiObjects = cgiObjects
		pass

	def __del__(self):
		base_template.BaseTemplate.__del__(self)

	def populateDataMap(self):
		#Overload to support dict objects as variables
		pass

	def extendSpecificParameters(self):
		#m_datamap.keys() must be first
		self.m_datamap[self.MAKEFILE_FILES] = ' '.join(cgiObj.getFileName() + ".cpp" for cgiObj in self.cgiObjects)
		#Executable MUST be after (order sensitive)
		self.m_datamap[self.MAKEFILE_PROGRAM_NAME] = self.binaryName



