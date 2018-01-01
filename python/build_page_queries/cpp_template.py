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

	def generateParameters(self):
		#All the specific files to output
		#Class name is "class_name"
		className = self.m_datamap[self.CPP_CLASS]
		titleClassList = className.split('_')
		titleClassName = ''.join( name.capitalize() for name in titleClassList)
		#Generators
		self.m_datamap[self.CLASS_NAME] = titleClassName
		self.m_datamap[self.HEADER_IFDEF] = className.upper() # UPPER
		self.m_datamap[self.CLASS_VARIABLES] = self.generateVariables();
		print self.m_datamap

	def generateVariables(self):
		#Get all the variable names
		output = str()
		variableName = Template("string\t\t\tm_$VARIABLE_NAME;\n\t\t")
		for variables in self.m_datamap.get(self.VARIABLE_LIST):
			output += variableName.safe_substitute(VARIABLE_NAME=variables)
		return output

	def generateSourceCode(self):
		#Output to the self.m_output_file
		#print self.m_template
		output = self.m_template.safe_substitute(self.m_datamap)
		print output
