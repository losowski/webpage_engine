#!/usr/bin/python
#Class to deal with the template for a CPP Implementation

#Import relative to executing python file
import cpp_template

from string import Template

class CPPImplementation (cpp_template.CPPTemplate):
	#Headers
	HPP_INCLUDE				=	'HEADER_INCLUDE'
	PARSE_CGI_PARAMETERS	=	'PARSE_CGI_PARAMETERS'
	PROCESS_SQL_RESULT		=	'PROCESS_SQL_RESULT'

	def __init__(self, output, dataDict):
		cpp_template.CPPTemplate.__init__(self, "page.cpp", output + ".cpp", dataDict)
		pass

	def __del__(self):
		cpp_template.CPPTemplate.__del__(self)

	def extendSpecificParameters(self):
		self.m_datamap[self.HPP_INCLUDE] = "#include \"" + self.m_datamap[self.RAWDATA_FILENAME] + ".hpp\"" #"#include "file_name"
		self.m_datamap[self.PARSE_CGI_PARAMETERS] = self.extendParseCGIParameters()
		self.m_datamap[self.PROCESS_SQL_RESULT] = self.extendProcesSQLResult()

	def extendParseCGIParameters(self):
		output = str()
		variableName = Template("\tparseCGIParameter(m_$VARIABLE_NAME, \"$PRETTY_VARIABLE_NAME\");\n")
		for variable, pretty_variable in zip(self.m_datamap.get(self.RAWDATA_VARIABLE_LIST), self.m_datamap.get(self.PRETTY_VARIABLE_LIST)):
			output += variableName.safe_substitute(VARIABLE_NAME=variable, PRETTY_VARIABLE_NAME=pretty_variable)
		return output

	def extendProcesSQLResult(self):
		output = str()
		variableName = Template("""\
		if (true == m_$VARIABLE_NAME.empty())\n\
		{\n\
		m_$VARIABLE_NAME.assign(res[i][\"$VARIABLE_NAME\"].c_str());\n\
		}\n\
		""")
		for variable in self.m_datamap.get(self.RAWDATA_VARIABLE_LIST):
			output += variableName.safe_substitute(VARIABLE_NAME=variable)
		return output
