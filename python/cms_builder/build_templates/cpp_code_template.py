#!/usr/bin/python
#Class to deal with the template for a CPP template
import base_template
from code_layouts import \
	basic_form, \
	basic_page \

from string import Template

class CPPCodeTemplate (base_template.BaseTemplate):
	#CONSTANTS FROM TEMPLATES
	RAWDATA_HEADER_IFDEF		=	'HEADER_IFDEF_HPP'
	RAWDATA_CLASS_NAME			=	'CLASS_NAME'
	RAWDATA_CLASS_VARIABLES		=	'CLASS_VARIABLES'
	PRETTY_VARIABLE_LIST		=	'PRETTY_VARIABLE_LIST'

	def __init__(self, templateFile, project, outputFile, className, baseClass, dbSchema, dbTableName, formDesign, variableList):
		base_template.BaseTemplate.__init__(self, templateFile, "cpp/lib"+project+"/" + outputFile)
		self.project = project
		self.className = className
		self.baseClass = baseClass
		self.dbSchema = dbSchema
		self.dbTableName = dbTableName
		self.formDesign = formDesign
		self.variableList = variableList
		self.prettyVariableList = None
		self.cgid = None
		#Populate
		self.definePageObject(formDesign)
		self.populateDataMap()

	def __del__(self):
		base_template.BaseTemplate.__del__(self)
		self.cgid = None
		pass

	def populateDataMap(self):
		self.dataMap = {	self.RAWDATA_FILENAME 		:	self.className,
							self.RAWDATA_BASE_CLASS 	:	self.baseClass,
							self.RAWDATA_DB_SCHEMA 		:	self.dbSchema,
							self.RAWDATA_TABLE_NAME		:	self.dbTableName,
							self.RAWDATA_VARIABLE_LIST	:	self.variableList,
						}

	def definePageObject(self, design = None):
		if design == "basicForm":
			self.cgid = basic_form.BasicForm(self.variableList)
		else:
			self.cgid = basic_page.BasicPage(self.variableList)
		print ("Page Type: {pagetype}".format(pagetype = self.cgid.getPageType()))
		#Build the CGID FORM
		self.cgid.formatData()

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
		for variable in self.variableList:
			splitVariable = variable[0].split('_')
			prettyVariable =  ' '.join( name.capitalize() for name in splitVariable)
			prettyVariableList.append(prettyVariable)
		self.prettyVariableList = prettyVariableList
		self.dataMap[self.PRETTY_VARIABLE_LIST] = prettyVariableList
		#, self.dataMap.get(self.PRETTY_VARIABLE_LIST)):


