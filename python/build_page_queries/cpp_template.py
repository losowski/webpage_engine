#!/usr/bin/python
#Class to deal with the template for a CPP template


class CPPTemplate:
	#CONSTANTS FROM TEMPLATES
	CPP_CLASS			=	"cpp_class"
	HEADER_IFDEF		=	"HEADER_IFDEF"
	CLASS_NAME			=	"CLASS_NAME"
	CLASS_VARIABLES		=	"CLASS_VARIABLES"

	def __init__(self, template_file, output_file, datamap):
		self.m_template_file = template_file
		self.m_output_file = output_file + ".hpp"
		self.m_datamap = datamap
		#Template Data
		self.m_template = str()


	def __del__(self):
		#Close the template file
		pass

	def loadTemplate(self):
		templateFile = open("templates/" + self.m_template_file, 'r')
		self.m_template = templateFile.read()
		templateFile.close()

	def generateParameters(self):
		#All the specific files to output
		#Class name is "class_name"
		class_name = self.m_datamap[CPP_CLASS]
		self.m_datamap[CLASS_NAME] = class_name #As is
		self.m_datamap[HEADER_IFDEF] = class_name.upper() # UPPER
		pass

	def generateSourceCode(self):
		#Output to the self.m_output_file
		pass

