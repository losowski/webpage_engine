#!/usr/bin/python
#Class to deal with the template for a CPP template
from string import Template

class CPPTemplate:
	#CONSTANTS FROM TEMPLATES
	CPP_CLASS			=	'cpp_class'
	HEADER_IFDEF		=	'HEADER_IFDEF_HPP'
	CLASS_NAME			=	'CLASS_NAME'
	CLASS_VARIABLES		=	'CLASS_VARIABLES'
	VARIABLE_LIST		=	'VARIABLE_LIST'

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

	def generateParametersTemplate(self):
		#All the specific files to output
		#Class name is "class_name"
		className = self.m_datamap[self.CPP_CLASS] #"file_name"
		titleClassList = className.split('_')
		titleClassName = ''.join( name.capitalize() for name in titleClassList)
		#Generators
		self.m_datamap[self.CLASS_NAME] = titleClassName #"FileName"
		self.m_datamap[self.HEADER_IFDEF] = className.upper() # "FILE_NAME"


	def generateSourceCode(self):
		output = self.m_template.safe_substitute(self.m_datamap)
		outputFile = open("../cpp/libwebcms/" + self.m_output_file, 'w')
		outputFile.write(output)
		outputFile.flush()
		outputFile.close()
