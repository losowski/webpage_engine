#!/usr/bin/python
#Class to deal with the template for a SQL Stored Procedure file

#Import relative to executing python file
import sql_template

from string import Template

class SQLStoredProc (sql_template.SQLTemplate):
	SQL_STOREDPROCNAME			= "SQL_STOREDPROCNAME"
	SQL_PARAMETER				= "SQL_PARAMETER"
	SQL_DECLARED				= "SQL_DECLARED"
	SQL_FIELDSSELECT4UPDATE		= "SQL_FIELDSSELECT4UPDATE"
	SQL_DECLARESELECT4UPDATE	= "SQL_DECLARESELECT4UPDATE"
	SQL_COMPAREVALUES4UPDATE	= "SQL_COMPAREVALUES4UPDATE"
	SQL_UPDATESETVALUE			= "SQL_UPDATESETVALUE"
	SQL_VARLIST					= "SQL_VARLIST"
	SQL_PARAMLIST				= "SQL_PARAMLIST"

	def __init__(self, dbSchema, dbTableName, variableList):
		sql_template.SQLTemplate.__init__(self, "stored_procedure.sql", "storedprocedures/" + dbTableName+"_procedure.sql", dbSchema, dbTableName, variableList)
		pass

	def __del__(self):
		sql_template.SQLTemplate.__del__(self)

	def populateDataMap(self):
		self.dataMap = {
							self.SQL_STOREDPROCNAME				:	SQLStoredProc.buildStoredProcName(self.dbSchema, self.dbTableName),
							self.SQL_SCHEMA_TABLE				:	sql_template.SQLTemplate.buildSchemaTable(self.dbSchema, self.dbTableName),
							self.SQL_PARAMETER					:	self.buildParameterList(),
							self.SQL_DECLARED					:	self.buildDeclaredList(),
							self.SQL_FIELDSSELECT4UPDATE		:	self.buildSelectField4UpdateList(),
							self.SQL_DECLARESELECT4UPDATE		:	self.buildSelectInto4UpdateList(),
							self.SQL_COMPAREVALUES4UPDATE		:	self.buildCompareValuesForUpdateList(),
							self.SQL_UPDATESETVALUE				:	self.buildUpdateSetValueList(),
							self.SQL_VARLIST					:	self.buildVarList(),
							self.SQL_PARAMLIST					:	self.buildParamList(),
						}

	#Build the Stored procedure Name
	#Static method
	@staticmethod
	def buildStoredProcName(dbSchema, dbTableName):
		#demo_schema.pInsUpdContact
		return "{dbSchema}.pInsUpd{dbTableName}".format(dbSchema=dbSchema, dbTableName=dbTableName)
		#NOTE: This is used in the CGI script
		# Important that the code is uniform - preferably calling this function only

	#Build the SQL parameters
	def buildParameter(self, var, declared, param, sqltype):
		#"IN	p_forename				demo_schema.tcontact.forename%TYPE default NULL,"
		return "\tIN\t{param}\t\t\t{SQL_SCHEMA_TABLE}.{var}%TYPE default NULL".format(var=var, param=param, SQL_SCHEMA_TABLE = sql_template.SQLTemplate.buildSchemaTable(self.dbSchema, self.dbTableName))

	def buildParameterList(self):
		return (",\n".join(self.buildParameter(var, declared, param, sqltype) for (var, declared, param, sqltype) in self.sqlVariableList))

	#Build the SQL Declared
	def buildDeclared(self, var, declared, param, sqltype):
		#"v_forename				demo_schema.tcontact.forename%TYPE;"
		return "\t{declared}\t\t\t{SQL_SCHEMA_TABLE}.{var}%TYPE;".format(var=var, declared=declared, SQL_SCHEMA_TABLE = sql_template.SQLTemplate.buildSchemaTable(self.dbSchema, self.dbTableName))

	def buildDeclaredList(self):
		return ("\n".join(self.buildDeclared(var, declared, param, sqltype) for (var, declared, param, sqltype) in self.sqlVariableList))

	#Build the SQL Select 4 Update Fields
	def buildSelectField4Update(self, var, declared, param, sqltype):
		#"COALESCE(p_forename, forename),"
		return "\t\tCOALESCE({param}, {var})".format(param=param, var=var)

	def buildSelectField4UpdateList(self):
		return (",\n".join(self.buildSelectField4Update(var, declared, param, sqltype) for (var, declared, param, sqltype) in self.sqlVariableList))

	#Build the SQL Select 4 Update Declare
	def buildSelectInto4Update(self, var, declared, param, sqltype):
		#"		v_forename,"
		return "\t\t{declared}".format(declared=declared)

	def buildSelectInto4UpdateList(self):
		return (",\n".join(self.buildSelectInto4Update(var, declared, param, sqltype) for (var, declared, param, sqltype) in self.sqlVariableList))

	#Build the SQL Select 4 Update Compare
	def buildCompareValuesForUpdate(self, var, declared, param, sqltype):
		#IF v_forename != p_forename AND p_forename IS NOT NULL THEN
		#	v_forename := p_forename;
		#END IF;
		return "\tIF {declared} != {param} AND {param} IS NOT NULL THEN\n\t\t{declared} := {param};\n\tEND IF;".format(var=var, param=param, declared=declared)

	def buildCompareValuesForUpdateList(self):
		return (",\n".join(self.buildCompareValuesForUpdate(var, declared, param, sqltype) for (var, declared, param, sqltype) in self.sqlVariableList))


	#Build the SQL Update Set value
	def buildUpdateSetValue(self, var, declared, param, sqltype):
		#forename = v_forename,
		return "\t\t{var} = {param}".format(var=var, param=param)

	def buildUpdateSetValueList(self):
		return (",\n".join(self.buildUpdateSetValue(var, declared, param, sqltype) for (var, declared, param, sqltype) in self.sqlVariableList))

	#Build var list
	def buildVar(self, var, declared, param, sqltype):
		#				forename
		return "\t\t\t\t{var}".format(var=var)

	def buildVarList(self):
		return (",\n".join(self.buildVar(var, declared, param, sqltype) for (var, declared, param, sqltype) in self.sqlVariableList))

	#Build param list
	def buildParam(self, var, declared, param, sqltype):
		#				p_forename
		return "\t\t\t\t{param}".format(param=param)

	def buildParamList(self):
		return (",\n".join(self.buildParam(var, declared, param, sqltype) for (var, declared, param, sqltype) in self.sqlVariableList))

