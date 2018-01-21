#!/usr/bin/python
#Class to deal with the template for a CPP Implementation

#Import relative to executing python file
import cpp_code_template

from string import Template

from code_layouts import \
	basic_form, \
	basic_page \

class CPPImplementation (cpp_code_template.CPPCodeTemplate):
	#Headers
	HPP_INCLUDE						=	'HEADER_INCLUDE'
	PARSE_CGI_PARAMETERS			=	'PARSE_CGI_PARAMETERS'
	BUILD_CGI_DESIGN				=	'BUILD_CGI_DESIGN'
	SQL_SELECT						=	'SQL_SELECT'
	PROCESS_SQL_RESULT				=	'PROCESS_SQL_RESULT'
	SQL_STORED_PROCEDURE_NAME		=	'SQL_STORED_PROCEDURE_NAME'
	SQL_STORED_PROCEDURE_PARAMETERS	=	'SQL_STORED_PROCEDURE_PARAMETERS'

	def __init__(self, fileName, baseClass, dbSchema, dbTableName, variableList):
		cpp_code_template.CPPCodeTemplate.__init__(self, "page.cpp", fileName + ".cpp", fileName, baseClass, dbSchema, dbTableName, variableList)
		pass

	def __del__(self):
		cpp_code_template.CPPCodeTemplate.__del__(self)

	def extendSpecificParameters(self):
		self.m_datamap[self.HPP_INCLUDE] = "#include \"" + self.m_datamap[self.RAWDATA_FILENAME] + ".hpp\"" #"#include "file_name"
		self.m_datamap[self.PARSE_CGI_PARAMETERS] = self.extendParseCGIParameters()
		self.m_datamap[self.BUILD_CGI_DESIGN] = self.buildCGIDesign("basicForm")
		self.m_datamap[self.SQL_SELECT] = self.extendSQLSelect()
		self.m_datamap[self.PROCESS_SQL_RESULT] = self.extendProcesSQLResult()
		self.m_datamap[self.SQL_STORED_PROCEDURE_NAME] = self.extendSQLStoredProcedureName()
		self.m_datamap[self.SQL_STORED_PROCEDURE_PARAMETERS] = self.extendSQLStoredProcedureParameters()

	def buildCGIDesign(self, design = None):
		if design == "basicForm":
			cgid = basic_form.BasicForm(self.m_datamap.get(self.RAWDATA_VARIABLE_LIST))
		else:
			cgid = basic_page.BasicPage(self.m_datamap.get(self.RAWDATA_VARIABLE_LIST))
		#Now Run the class
		cgid.buildPage()
		return cgid.getPage()

	def extendParseCGIParameters(self):
		output = str()
		variableName = Template("\tparseCGIParameter(m_$VARIABLE_NAME, \"$PRETTY_VARIABLE_NAME\");\n")
		for variable, pretty_variable in zip(self.m_datamap.get(self.RAWDATA_VARIABLE_LIST), self.m_datamap.get(self.PRETTY_VARIABLE_LIST)):
			output += variableName.safe_substitute(VARIABLE_NAME=variable, PRETTY_VARIABLE_NAME=pretty_variable)
		return output

	def extendSQLSelect(self):
		return ',\\\n\t\t'.join( name for name in self.m_datamap.get(self.RAWDATA_VARIABLE_LIST))

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

	def extendSQLStoredProcedureName(self):
		variableName = Template('pInsUpd$RAWDATA_TABLE_NAME')
		output = variableName.safe_substitute(RAWDATA_TABLE_NAME=self.m_datamap.get(self.RAWDATA_TABLE_NAME).capitalize())
		return output

	def extendSQLStoredProcedureParameters(self):
		output = str()
		variableName = Template(" + \",\"  + txn.quote(m_$VARIABLE_NAME)")
		for variable in self.m_datamap.get(self.RAWDATA_VARIABLE_LIST):
			output += variableName.safe_substitute(VARIABLE_NAME=variable)
		return output
