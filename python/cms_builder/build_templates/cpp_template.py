#!/usr/bin/python
#Generic Template handling
from string import Template

class CPPTemplate:
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
		#Nothing normally here. Made for specialisations
		pass

	def extendSpecificParameters(self):
		#Overload
		pass

	def generateSourceCode(self):
		output = self.m_template.safe_substitute(self.m_datamap)
		outputFile = open("../cpp/libwebcms/" + self.m_output_file, 'w')
		outputFile.write(output)
		outputFile.flush()
		outputFile.close()
