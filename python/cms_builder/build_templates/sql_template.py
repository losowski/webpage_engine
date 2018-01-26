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
			declared = "v_" + var
			param = "p_" + var
			self.sqlVariableList.append((var, declared, param)) #tuple


