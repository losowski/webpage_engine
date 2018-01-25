#!/usr/bin/python
#Generic Template handling
from string import Template

class BaseTemplate:
	#CONSTANTS FROM TEMPLATES
	RAWDATA_FILENAME			=	'rawdata_file_name'
	RAWDATA_BASE_CLASS			=	'RAWDATA_BASE_CLASS'
	RAWDATA_DB_SCHEMA			=	'RAWDATA_DB_SCHEMA'
	RAWDATA_TABLE_NAME			=	'RAWDATA_TABLE_NAME'
	RAWDATA_VARIABLE_LIST		=	'VARIABLE_LIST'

	def __init__(self, templateFile, outputFile):
		self.templateFile = templateFile
		self.outputFile = outputFile
		#Template datamap	
		self.dataMap = dict()
		#Template contents
		self.m_template = str()

	def __del__(self):
		#Close the template file
		pass

	def populateDataMap(self):
		#Overload to support dict objects as variables	
		pass

	def loadTemplate(self):
		print ("Loading template {templatefile}".format(templatefile = self.templateFile))
		templateFile = open("templates/" + self.templateFile, 'r')
		contents = templateFile.read()
		self.m_template = Template(contents)
		templateFile.close()

	def generateParameters(self):
		#Basic Functionality
		self.generateParametersTemplate()
		#User Specific Functionality
		self.extendSpecificParameters()

	def generateParametersTemplate(self):
		#Nothing normally here. Made for specialisations
		pass

	def extendSpecificParameters(self):
		#Overload
		pass

	def generateSourceCode(self):
		print ("Genearating source code file {outputfile}".format(outputfile = self.outputFile))
		output = self.m_template.safe_substitute(self.dataMap)
		outputFile = open("../" + self.outputFile, 'w')
		outputFile.write(output)
		outputFile.flush()
		outputFile.close()
