#!/usr/bin/python
#Class to deal with the template for a CPP Implementation

#Import relative to executing python file
import base_template

from string import Template

class BinMakefile (base_template.BaseTemplate):
	#Headers
	MAKEFILE_PROGRAM_NAME	=	'MAKEFILE_PROGRAM_NAME'

	def __init__(self, project, output, binaryName, cgiObjects ):
		base_template.BaseTemplate.__init__(self, "bin_makefile", "cpp/bin"+project+"/" + output)
		self.binaryName = binaryName
		self.cgiObjects = cgiObjects
		pass

	def __del__(self):
		base_template.BaseTemplate.__del__(self)

	def populateDataMap(self):
		#Overload to support dict objects as variables
		pass

	def extendSpecificParameters(self):
		#Executable MUST be after (order sensitive)
		self.dataMap[self.MAKEFILE_PROGRAM_NAME] = self.binaryName



