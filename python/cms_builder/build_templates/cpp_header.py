#!/usr/bin/python
#Class to deal with the template for a CPP header

#Import relative to executing python file
import cpp_code_template

from string import Template

class CPPHeader (cpp_code_template.CPPCodeTemplate):
	def __init__(self, project, className, baseClass, dbSchema, dbTableName, formDesign, variableList):
		cpp_code_template.CPPCodeTemplate.__init__(self, "page.hpp", project, className + ".hpp", className, baseClass, dbSchema, dbTableName, formDesign, variableList)
		pass

	def __del__(self):
		cpp_code_template.CPPCodeTemplate.__del__(self)

	def extendSpecificParameters(self):
		self.dataMap[self.RAWDATA_CLASS_VARIABLES] = self.generateVariables();

	def generateVariables(self):
		#Get all the variable names
		output = str()
		variableName = Template("string\t\t\tm_$VARIABLE_NAME;\n\t\t")
		for variables in self.variableList:
			output += variableName.safe_substitute(VARIABLE_NAME=variables[0])
		return output
