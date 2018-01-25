#!/usr/bin/python
#Class to deal with the template for a CPP Implementation

#Import relative to executing python file
import sql_template

from string import Template

class SQLCreateTable (sql_template.SQLTemplate):
	#Headers
	MAKEFILE_FILES			=	'MAKEFILE_FILES'
	MAKEFILE_PROGRAM_NAME	=	'MAKEFILE_PROGRAM_NAME'

	def __init__(self, output, binaryName, cgiObjects ):
		sql_template.SQLTemplate.__init__(self, "makefile", output)
		self.binaryName = binaryName
		self.cgiObjects = cgiObjects
		pass

	def __del__(self):
		sql_template.SQLTemplate.__del__(self)

	def populateDataMap(self):
		#Overload to support dict objects as variables
		pass

	def extendSpecificParameters(self):
		#dataMap.keys() must be first
		self.dataMap[self.MAKEFILE_FILES] = ' '.join(cgiObj.getFileName() + ".cpp" for cgiObj in self.cgiObjects)
		#Executable MUST be after (order sensitive)
		self.dataMap[self.MAKEFILE_PROGRAM_NAME] = self.binaryName



