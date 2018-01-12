#!/usr/bin/python
#Class to deal with the template for a CPP header

#Import relative to executing python file
import cpp_template

from string import Template

class CPPHeader (cpp_template.CPPTemplate):
	def __init__(self, output, dataDict):
		cpp_template.CPPTemplate.__init__(self, "page.hpp", output + ".hpp", dataDict)
		pass

	def __del__(self):
		cpp_template.CPPTemplate.__del__(self)

	def extendSpecificParameters(self):
		self.m_datamap[self.CLASS_VARIABLES] = self.generateVariables();

	def generateVariables(self):
		#Get all the variable names
		output = str()
		variableName = Template("string\t\t\tm_$VARIABLE_NAME;\n\t\t")
		for variables in self.m_datamap.get(self.VARIABLE_LIST):
			output += variableName.safe_substitute(VARIABLE_NAME=variables)
		return output
