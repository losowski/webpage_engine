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
	BINARY_NAME						=	'BINARY_NAME'

	def __init__(self, project, className, baseClass, dbSchema, dbTableName, formDesign, variableList):
		cpp_code_template.CPPCodeTemplate.__init__(self, "page.cpp", project, className + ".cpp", className, baseClass, dbSchema, dbTableName, formDesign, variableList)
		pass

	def __del__(self):
		cpp_code_template.CPPCodeTemplate.__del__(self)


	def extendSpecificParameters(self):
		self.dataMap[self.HPP_INCLUDE] = "#include \"" + self.dataMap[self.RAWDATA_FILENAME] + ".hpp\"" #"#include "file_name"
		self.dataMap[self.PARSE_CGI_PARAMETERS] = self.buildCGIInputList()
		self.dataMap[self.BUILD_CGI_DESIGN] = self.buildCGIDesignList()
		self.dataMap[self.SQL_SELECT] = self.extendSQLSelect()
		self.dataMap[self.PROCESS_SQL_RESULT] = self.extendProcesSQLResult()
		self.dataMap[sql_stored_proc.SQLStoredProc.SQL_SCHEMA_TABLE] = sql_template.SQLTemplate.buildSchemaTable(self.dbSchema, self.dbTableName)
		self.dataMap[sql_stored_proc.SQLStoredProc.SQL_STOREDPROCNAME] = sql_stored_proc.SQLStoredProc.buildStoredProcName(self.dbSchema, self.dbTableName)
		self.dataMap[self.SQL_STORED_PROCEDURE_PARAMETERS] = self.extendSQLStoredProcedureParameters()
		self.dataMap[self.BINARY_NAME] = self.project

	def buildCGIDesign(self, val):
		fieldTitle = self.fieldNameToTitleName(val)
		return self.cgid.buildCGIFormDesign(val, fieldTitle)

	def buildCGIDesignList(self):
		return ("\n".join(self.buildCGIDesign(var) for (var, sqltype) in self.variableList))

	def buildCGIInput(self, val):
		return self.cgid.buildCGIFormInput(val)

	def buildCGIInputList(self):
		return ("\n".join(self.buildCGIInput(var) for (var, sqltype) in self.variableList))

	def extendSQLSelect(self):
		return ',\\\n\t\t'.join( name[0] for name in self.variableList)

	def extendProcesSQLResult(self):
		output = str()
		variableName = Template("""\
		if (true == m_$VARIABLE_NAME.empty())\n\
		{\n\
		m_$VARIABLE_NAME.assign(res[i][\"$VARIABLE_NAME\"].c_str());\n\
		}\n\
		""")
		for variable in self.variableList:
			output += variableName.safe_substitute(VARIABLE_NAME=variable[0])
		return output

	def extendSQLStoredProcedureParameters(self):
		output = str()
		variableName = Template(" + \",\"  + txn.quote(m_$VARIABLE_NAME)")
		for variable in self.variableList:
			output += variableName.safe_substitute(VARIABLE_NAME=variable[0])
		return output
