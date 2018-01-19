#!/usr/bin/python
#Class to deal with the template for a CPP template
import cpp_template

from string import Template

class CPPCodeTemplate (cpp_template.CPPTemplate):
	#CONSTANTS FROM TEMPLATES
	RAWDATA_HEADER_IFDEF		=	'HEADER_IFDEF_HPP'
	RAWDATA_CLASS_NAME			=	'CLASS_NAME'
	RAWDATA_CLASS_VARIABLES		=	'CLASS_VARIABLES'
	PRETTY_VARIABLE_LIST		=	'PRETTY_VARIABLE_LIST'

	def __init__(self, templateFile, outputFile, dataDict):
		cpp_template.CPPTemplate.__init__(self, templateFile, outputFile, dataDict)


	def __del__(self):
		cpp_template.CPPTemplate.__del__(self)
		pass

	def generateParametersTemplate(self):
		#All the specific files to output
		#BaseClass
		if (None == self.m_datamap.get(self.RAWDATA_BASE_CLASS)):
			self.m_datamap[self.RAWDATA_BASE_CLASS] = "WebPageBase"
		#Class name is "class_name"
		className = self.m_datamap[self.RAWDATA_FILENAME] #"file_name"
		titleClassList = className.split('_')
		titleClassName = ''.join( name.capitalize() for name in titleClassList)
		#Generators
		self.m_datamap[self.RAWDATA_CLASS_NAME] = titleClassName #"FileName"
		self.m_datamap[self.RAWDATA_HEADER_IFDEF] = className.upper() + "_HPP" # "FILE_NAME"
		#Variable list
		prettyVariableList = list()
		for variable in self.m_datamap.get(self.RAWDATA_VARIABLE_LIST):
			splitVariable = variable.split('_')
			prettyVariable =  ' '.join( name.capitalize() for name in splitVariable)
			prettyVariableList.append(prettyVariable)
		self.m_datamap[self.PRETTY_VARIABLE_LIST] = prettyVariableList
		#, self.m_datamap.get(self.PRETTY_VARIABLE_LIST)):


