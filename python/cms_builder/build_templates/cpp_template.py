#!/usr/bin/python
#Class to deal with the template for a CPP template
from string import Template

class CPPTemplate:
	#CONSTANTS FROM TEMPLATES
	RAWDATA_FILENAME			=	'rawdata_file_name'
	RAWDATA_TABLE_NAME			=	'RAWDATA_TABLE_NAME'
	RAWDATA_DB_SCHEMA			=	'RAWDATA_DB_SCHEMA'
	RAWDATA_HEADER_IFDEF		=	'HEADER_IFDEF_HPP'
	RAWDATA_CLASS_NAME			=	'CLASS_NAME'
	RAWDATA_CLASS_VARIABLES		=	'CLASS_VARIABLES'
	RAWDATA_VARIABLE_LIST		=	'VARIABLE_LIST'
	PRETTY_VARIABLE_LIST		=	'PRETTY_VARIABLE_LIST'

	def __init__(self, template_file, output_file, datamap):
		self.m_template_file = template_file
		self.m_output_file = output_file
		self.m_datamap = datamap
		#Template Data
		self.m_template = str()


	def __del__(self):
		#Close the template file
		pass

	def loadTemplate(self):
		templateFile = open("templates/" + self.m_template_file, 'r')
		contents = templateFile.read()
		self.m_template = Template(contents)
		templateFile.close()

	def generateParameters(self):
		#Basic Functionality
		self.generateParametersTemplate()
		#User Specific Functionality
		self.extendSpecificParameters()

	def generateParametersTemplate(self):
		#All the specific files to output
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

	def extendSpecificParameters(self):
		#Overload
		pass

	def generateSourceCode(self):
		output = self.m_template.safe_substitute(self.m_datamap)
		outputFile = open("../cpp/libwebcms/" + self.m_output_file, 'w')
		outputFile.write(output)
		outputFile.flush()
		outputFile.close()
