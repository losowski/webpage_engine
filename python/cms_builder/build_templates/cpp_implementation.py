#!/usr/bin/python
#Class to deal with the template for a CPP Implementation

#Import relative to executing python file
import cpp_code_template
import sql_template
import sql_stored_proc

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
	SQL_STORED_PROCEDURE_PARAMETERS	=	'SQL_STORED_PROCEDURE_PARAMETERS'

	def __init__(self, className, baseClass, dbSchema, dbTableName, formDesign, variableList):
		cpp_code_template.CPPCodeTemplate.__init__(self, "page.cpp", className + ".cpp", className, baseClass, dbSchema, dbTableName, formDesign, variableList)
		pass

	def __del__(self):
		cpp_code_template.CPPCodeTemplate.__del__(self)


	def extendSpecificParameters(self):
		self.dataMap[self.HPP_INCLUDE] = "#include \"" + self.dataMap[self.RAWDATA_FILENAME] + ".hpp\"" #"#include "file_name"
		self.dataMap[self.PARSE_CGI_PARAMETERS] = self.extendParseCGIParameters()
		self.dataMap[self.BUILD_CGI_DESIGN] = self.buildCGIDesign(self.formDesign)
		self.dataMap[self.SQL_SELECT] = self.extendSQLSelect()
		self.dataMap[self.PROCESS_SQL_RESULT] = self.extendProcesSQLResult()
		self.dataMap[sql_stored_proc.SQLStoredProc.SQL_SCHEMA_TABLE] = sql_template.SQLTemplate.buildSchemaTable(self.dbSchema, self.dbTableName)
		self.dataMap[sql_stored_proc.SQLStoredProc.SQL_STOREDPROCNAME] = sql_stored_proc.SQLStoredProc.buildStoredProcName(self.dbSchema, self.dbTableName)
		self.dataMap[self.SQL_STORED_PROCEDURE_PARAMETERS] = self.extendSQLStoredProcedureParameters()

	def buildCGIDesign(self, design = None):
		if design == "basicForm":
			cgid = basic_form.BasicForm(self.variableList)
		else:
			cgid = basic_page.BasicPage(self.variableList)
		#Now Run the class
		cgid.buildPage()
		return cgid.getPage()

	def extendParseCGIParameters(self):
		output = str()
		variableName = Template("\tparseCGIParameter(m_$VARIABLE_NAME, \"$PRETTY_VARIABLE_NAME\");\n")
		for variable, pretty_variable in zip(self.variableList, self.prettyVariableList):
			output += variableName.safe_substitute(VARIABLE_NAME=variable, PRETTY_VARIABLE_NAME=pretty_variable)
		return output

	def extendSQLSelect(self):
		return ',\\\n\t\t'.join( name for name in self.variableList)

	def extendProcesSQLResult(self):
		output = str()
		variableName = Template("""\
		if (true == m_$VARIABLE_NAME.empty())\n\
		{\n\
		m_$VARIABLE_NAME.assign(res[i][\"$VARIABLE_NAME\"].c_str());\n\
		}\n\
		""")
		for variable in self.variableList:
			output += variableName.safe_substitute(VARIABLE_NAME=variable)
		return output

	def extendSQLStoredProcedureParameters(self):
		output = str()
		variableName = Template(" + \",\"  + txn.quote(m_$VARIABLE_NAME)")
		for variable in self.variableList:
			output += variableName.safe_substitute(VARIABLE_NAME=variable)
		return output
