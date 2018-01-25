#!/usr/bin/python
#Class to deal with the template for a CPP template
import base_template

from string import Template

class SQLTemplate (base_template.BaseTemplate):
	#CONSTANTS FROM TEMPLATES
	RAWDATA_HEADER_IFDEF		=	'HEADER_IFDEF_HPP'
	RAWDATA_CLASS_NAME			=	'CLASS_NAME'
	RAWDATA_CLASS_VARIABLES		=	'CLASS_VARIABLES'
	PRETTY_VARIABLE_LIST		=	'PRETTY_VARIABLE_LIST'

	def __init__(self, templateFile, outputFile, className, baseClass, dbSchema, dbTableName, formDesign, variableList):
		base_template.BaseTemplate.__init__(self, templateFile, outputFile)
		self.className = className
		self.baseClass = baseClass
		self.dbSchema = dbSchema
		self.dbTableName = dbTableName
		self.formDesign = formDesign
		self.variableList = variableList
		self.prettyVariableList = None
		#Populate
		self.populateDataMap()

	def __del__(self):
		base_template.BaseTemplate.__del__(self)
		pass

	def populateDataMap(self):
		self.m_datamap = {	self.RAWDATA_FILENAME 		:	self.className,
							self.RAWDATA_BASE_CLASS 	:	self.baseClass,
							self.RAWDATA_DB_SCHEMA 		:	self.dbSchema,
							self.RAWDATA_TABLE_NAME		:	self.dbTableName,
							self.RAWDATA_VARIABLE_LIST	:	self.variableList,
						}

	def generateParametersTemplate(self):
		#All the specific files to output
		#BaseClass
		if (None == self.baseClass):
			self.m_datamap[self.RAWDATA_BASE_CLASS] = "WebPageBase"
		#Class name is "class_name"
		titleClassList = self.className.split('_')
		titleClassName = ''.join( name.capitalize() for name in titleClassList)
		#Generators
		self.m_datamap[self.RAWDATA_CLASS_NAME] = titleClassName #"FileName"
		self.m_datamap[self.RAWDATA_HEADER_IFDEF] = self.className.upper() + "_HPP" # "FILE_NAME"
		#Variable list
		prettyVariableList = list()
		for variable in self.m_datamap.get(self.RAWDATA_VARIABLE_LIST):
			splitVariable = variable.split('_')
			prettyVariable =  ' '.join( name.capitalize() for name in splitVariable)
			prettyVariableList.append(prettyVariable)
		self.prettyVariableList = prettyVariableList
		self.m_datamap[self.PRETTY_VARIABLE_LIST] = prettyVariableList
		#, self.m_datamap.get(self.PRETTY_VARIABLE_LIST)):


