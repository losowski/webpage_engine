#!/usr/bin/python
#Class to deal with the template for a SQL template
"""
	DESIGN:
	- Template file offers the general strucure
	- Wave 1 of templates builds a numbered template (i.e numbered for each field)
		-- Above two functions are to be called from loadTemplate - so we need to edit that function
	- Wave 2 Populates those numbers with field_names
	- Output is returned to the calling function
"""

import base_template

from string import Template

class SQLTemplate (base_template.BaseTemplate):
	SQL_SCHEMA_TABLE			= "SQL_SCHEMA_TABLE"

	def __init__(self, templateFile, outputFile, dbSchema, dbTableName, variableList):
		base_template.BaseTemplate.__init__(self, templateFile, "database/" + outputFile)
		self.dbSchema = dbSchema
		self.dbTableName = dbTableName
		self.variableList = variableList
		self.sqlVariableList = list()
		#Populate
		self.__initialiseVariableLists(variableList)
		self.populateDataMap()

	def __del__(self):
		base_template.BaseTemplate.__del__(self)
		pass

	def __initialiseVariableLists (self, variableList):
		for var in variableList:
			declared = "v_" + var[0]
			param = "p_" + var[0]
			sqltype = var[1]
			self.sqlVariableList.append((var[0], declared, param, sqltype)) #tuple

	#Build the table Schema Name
	@staticmethod
	def buildSchemaTable(dbSchema, dbTableName):
		return "{dbSchema}.t{dbTableName}".format(dbSchema=dbSchema, dbTableName=dbTableName)


