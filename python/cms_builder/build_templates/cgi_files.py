#!/usr/bin/python
#Generic Template handling

import cpp_implementation
import cpp_header

class CGIFiles:
	def __init__(self, className, baseClass, dbSchema, dbTableName, formDesign, variableList):
		self.className = className
		self.baseClass = baseClass
		self.dbSchema = dbSchema
		self.dbTableName = dbTableName
		self.formDesign = formDesign
		self.variableList = variableList
		#Objects
		self.implementation = None
		self.header = None

	def __del__(self):
		#Close the template file
		pass

	def getFileName(self):
		return self.className

	def initialize(self):
		self.implementation = cpp_implementation.CPPImplementation(
								className = self.className,
								baseClass = self.baseClass,
								dbSchema = self.dbSchema,
								dbTableName = self.dbTableName,
								formDesign = self.formDesign,
								variableList = self.variableList
							)
		self.header = cpp_header.CPPHeader(
								className = self.className,
								baseClass = self.baseClass,
								dbSchema = self.dbSchema,
								dbTableName = self.dbTableName,
								formDesign = self.formDesign,
								variableList = self.variableList
							)

	def loadTemplate(self):
		self.implementation.loadTemplate()
		self.header.loadTemplate()

	def generateParameters(self):
		self.implementation.generateParameters()
		self.header.generateParameters()

	def generateSourceCode(self):
		self.implementation.generateSourceCode()
		self.header.generateSourceCode()
