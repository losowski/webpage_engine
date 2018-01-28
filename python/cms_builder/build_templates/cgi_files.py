#!/usr/bin/python
#Generic Template handling

import cpp_implementation
import cpp_header
import sql_stored_proc
import sql_create_table

class CGIFiles:
	def __init__(self, className, baseClass, dbSchema, dbTableName, formDesign, variableList):
		self.className = className
		self.baseClass = baseClass
		self.dbSchema = dbSchema
		self.dbTableName = dbTableName
		self.formDesign = formDesign
		self.variableList = variableList
		#Objects
		self.buildObjects = list()

	def __del__(self):
		#Close the template file
		pass

	def getFileName(self):
		return self.className

	def initialize(self):
		self.buildObjects = [	cpp_header.CPPHeader(
									className = self.className,
									baseClass = self.baseClass,
									dbSchema = self.dbSchema,
									dbTableName = self.dbTableName,
									formDesign = self.formDesign,
									variableList = self.variableList
								),
								cpp_implementation.CPPImplementation(
									className = self.className,
									baseClass = self.baseClass,
									dbSchema = self.dbSchema,
									dbTableName = self.dbTableName,
									formDesign = self.formDesign,
									variableList = self.variableList
								),
								sql_stored_proc.SQLStoredProc(
									dbSchema = self.dbSchema,
									dbTableName = self.dbTableName,
									variableList = self.variableList
								),
								sql_create_table.SQLCreateTable(
									dbSchema = self.dbSchema,
									dbTableName = self.dbTableName,
									variableList = self.variableList
								)
							]

	def buildCGIComponents(self):
		for obj in self.buildObjects:
			obj.loadTemplate()
			obj.generateParameters()
			obj.generateSourceCode()
