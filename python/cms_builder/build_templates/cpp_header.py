#!/usr/bin/python
#Class to deal with the template for a CPP header

#Import relative to executing python file
import cpp_code_template

from string import Template

class CPPHeader (cpp_code_template.CPPCodeTemplate):
	def __init__(self, output, dataDict):
		cpp_code_template.CPPCodeTemplate.__init__(self, "page.hpp", output + ".hpp", dataDict)
		pass

	def __del__(self):
		cpp_code_template.CPPCodeTemplate.__del__(self)

	def extendSpecificParameters(self):
		self.m_datamap[self.RAWDATA_CLASS_VARIABLES] = self.generateVariables();

	def generateVariables(self):
		#Get all the variable names
		output = str()
		variableName = Template("string\t\t\tm_$VARIABLE_NAME;\n\t\t")
		for variables in self.m_datamap.get(self.RAWDATA_VARIABLE_LIST):
			output += variableName.safe_substitute(VARIABLE_NAME=variables)
		return output
