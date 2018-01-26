#!/usr/bin/python
#Class to deal with the template for a SQL Stored Procedure file

#Import relative to executing python file
import sql_template

from string import Template

class SQLStoredProc (sql_template.SQLTemplate):
	SQL_PARAMETER = "SQL_PARAMETER"
	SQL_DECLARED = "SQL_DECLARED"

	def __init__(self, dbSchema, dbTableName, variableList):
		sql_template.SQLTemplate.__init__(self, "stored_procedure.sql", "storedprocedures/" + dbTableName+"_procedure.sql", dbSchema, dbTableName, variableList)
		pass

	def __del__(self):
		sql_template.SQLTemplate.__del__(self)

	def populateDataMap(self):
		self.dataMap = {	self.SQL_PARAMETER	:	self.buildParameterList(),
							self.SQL_DECLARED	:	self.buildDeclaredList(),
						}

	#Build the SQL parameters
	def buildParameter(self, var, declared, param):
		#"IN	p_forename				demo_schema.tcontact.forename%TYPE default NULL,"
		return "\tIN\t{param}\t\t\t{dbSchema}.{dbTableName}.{var}%TYPE default NULL".format(param=param, dbSchema=self.dbSchema, dbTableName=self.dbTableName, var=var)

	def buildParameterList(self):
		return (",\n".join(self.buildParameter(var, declared, param) for (var, declared, param) in self.sqlVariableList))

	#Build the SQL Declared
	def buildDeclared(self, var, declared, param):
		#"v_forename				demo_schema.tcontact.forename%TYPE;"
		return "\t{declared}\t\t\t{dbSchema}.{dbTableName}.{var}%TYPE;".format(declared=declared, dbSchema=self.dbSchema, dbTableName=self.dbTableName, var=var)

	def buildDeclaredList(self):
		return ("\n".join(self.buildDeclared(var, declared, param) for (var, declared, param) in self.sqlVariableList))
