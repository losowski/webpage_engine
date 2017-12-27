#!/usr/bin/python
#Class to deal with the template for a CPP template

class CPPTemplage:
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
		pass

	def generateSourceCode(self):
		#Output to the self.m_output_file
		pass

