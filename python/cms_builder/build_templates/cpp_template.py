#!/usr/bin/python
#Generic Template handling
from string import Template

class CPPTemplate:
	#CONSTANTS FROM TEMPLATES
	RAWDATA_FILENAME			=	'rawdata_file_name'
	RAWDATA_BASE_CLASS			=	'RAWDATA_BASE_CLASS'
	RAWDATA_DB_SCHEMA			=	'RAWDATA_DB_SCHEMA'
	RAWDATA_TABLE_NAME			=	'RAWDATA_TABLE_NAME'
	RAWDATA_VARIABLE_LIST		=	'VARIABLE_LIST'

	def __init__(self, templateFile, outputFile, fileName):
		self.m_templateFile = templateFile
		self.m_outputFile = outputFile
		self.fileName = fileName
		#Template datamap	
		self.m_datamap = dict()
		#Template contents
		self.m_template = str()

	def __del__(self):
		#Close the template file
		pass

	def populateDataMap(self):
		#Overload to support dict objects as variables	
		pass

	def loadTemplate(self):
		print ("Loading template {templatefile}".format(templatefile = self.m_templateFile))
		templateFile = open("templates/" + self.m_templateFile, 'r')
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
		print ("Genearating source code file {outputfile}".format(outputfile = self.m_outputFile))
		output = self.m_template.safe_substitute(self.m_datamap)
		outputFile = open("../cpp/libwebcms/" + self.m_outputFile, 'w')
		outputFile.write(output)
		outputFile.flush()
		outputFile.close()
