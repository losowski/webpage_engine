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
		self.prettyVariableList = None
		#Populate
		self.populateDataMap()

	def __del__(self):
		base_template.BaseTemplate.__del__(self)
		pass

	def populateDataMap(self):
		self.dataMap = {	self.RAWDATA_FILENAME 		:	self.className,
							self.RAWDATA_BASE_CLASS 	:	self.baseClass,
							self.RAWDATA_DB_SCHEMA 		:	self.dbSchema,
							self.RAWDATA_TABLE_NAME		:	self.dbTableName,
							self.RAWDATA_VARIABLE_LIST	:	self.variableList,
						}

	def generateParametersTemplate(self):
		#All the specific files to output
		#BaseClass
		if (None == self.baseClass):
			self.dataMap[self.RAWDATA_BASE_CLASS] = "WebPageBase"
		#Class name is "class_name"
		titleClassList = self.className.split('_')
		titleClassName = ''.join( name.capitalize() for name in titleClassList)
		#Generators
		self.dataMap[self.RAWDATA_CLASS_NAME] = titleClassName #"FileName"
		self.dataMap[self.RAWDATA_HEADER_IFDEF] = self.className.upper() + "_HPP" # "FILE_NAME"
		#Variable list
		prettyVariableList = list()
		for variable in self.dataMap.get(self.RAWDATA_VARIABLE_LIST):
			splitVariable = variable.split('_')
			prettyVariable =  ' '.join( name.capitalize() for name in splitVariable)
			prettyVariableList.append(prettyVariable)
		self.prettyVariableList = prettyVariableList
		self.dataMap[self.PRETTY_VARIABLE_LIST] = prettyVariableList
		#, self.dataMap.get(self.PRETTY_VARIABLE_LIST)):

