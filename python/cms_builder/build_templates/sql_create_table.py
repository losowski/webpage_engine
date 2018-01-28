#!/usr/bin/python
#Class to deal with the template for creating the database table

#Import relative to executing python file
import sql_template

from string import Template

class SQLCreateTable (sql_template.SQLTemplate):
	SQL_CREATECOLUMS = "SQL_CREATECOLUMS"

	def __init__(self, dbSchema, dbTableName, variableList):
		sql_template.SQLTemplate.__init__(self, "create_table.sql", "create_"+dbTableName+"_table.sql", dbSchema, dbTableName, variableList)
		pass

	def __del__(self):
		sql_template.SQLTemplate.__del__(self)

	def populateDataMap(self):
		self.dataMap = {
							self.SQL_SCHEMA_TABLE				:	sql_template.SQLTemplate.buildSchemaTable(self.dbSchema, self.dbTableName),
							self.SQL_CREATECOLUMS				:	self.buildColumnsList(),
						}

	#Build the SQL parameters
	def buildColumns(self, var, declared, param):
		#"forename text NOT NULL,"
		return "\t{var} {type} NOT NULL".format(var=var, param=param, dbSchema=self.dbSchema, dbTableName=self.dbTableName)

	def buildColumnsList(self):
		return (",\n".join(self.buildColumns(var, declared, param) for (var, declared, param) in self.sqlVariableList))
