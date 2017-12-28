#!/usr/bin/python
#Class to deal with the template for a CPP template


class CPPTemplage:
	#CONST
	CPP_CLASS		=	"cpp_class"
	HEADER_IFDEF	=	"HEADER_IFDEF"
	CLASS_NAME		=	"CLASS_NAME"

	def __init__(self, template_file, output_file, datamap):
		self.m_template_name = template_file
		self.m_output_file = output
		self.m_datamap = datamap
		self.m_template = str()


	def __del__(self):
		#Close the template file
		pass

	def loadTemplate(self):
		templatFile = open("../template/" + self.m_template_file, 'r')
		self.m_template = self.templatFile.read()
		self.templatFile.close()

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

