#!/usr/bin/python
#Generic Template handling

import cpp_implementation
import cpp_header

class CGIFiles:
	def __init__(self, fileName, baseClass, dbSchema, dbTableName, variableList):
		self.fileName = fileName
		self.baseClass = baseClass
		self.dbSchema = dbSchema
		self.dbTableName = dbTableName
		self.variableList = variableList
		#Objects
		self.implementation = None
		self.header = None

	def __del__(self):
		#Close the template file
		pass

	def getFileName(self):
		return self.fileName

	def loadTemplate(self):
		self.implementation = cpp_implementaton.CPPImplementation(self.fileName, self.baseClass, self.dbSchema, self.dbTableName, self.variableList)
		self.header = cpp_header.CPPHeader(self.fileName, self.baseClass, self.dbSchema, self.dbTableName, self.variableList)

	def generateParameters(self):
		self.implementation.generateParameters()
		self.header.generateParameters()

	def generateSourceCode(self):
		self.implementation.generateSourceCode()
		self.header.generateSourceCode()
