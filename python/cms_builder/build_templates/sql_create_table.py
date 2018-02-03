#!/usr/bin/python
#Class to deal with the template for creating the database table

#Import relative to executing python file
import sql_template

from string import Template

class SQLCreateTable (sql_template.SQLTemplate):
	SQL_DATABASE_NAME	=	"SQL_DATABASE_NAME"
	SQL_DATABASE_USER	=	"SQL_DATABASE_USER"
	SQL_CREATECOLUMS	=	"SQL_CREATECOLUMS"
	SQL_TABLE_INDEX_ID	=	"SQL_TABLE_INDEX_ID"
	SQL_TABLE_INDEX		=	"SQL_TABLE_INDEX"


	def __init__(self, databaseName, databaseUser, dbSchema, dbTableName, variableList):
		self.databaseName = databaseName
		self.databaseUser = databaseUser
		#This calls populateDataMap! so put class specific variables above if it is used there
		sql_template.SQLTemplate.__init__(self, "create_table.sql", "create_"+dbTableName+"_table.sql", dbSchema, dbTableName, variableList)
		pass

	def __del__(self):
		sql_template.SQLTemplate.__del__(self)

	def populateDataMap(self):
		self.dataMap = {
							self.SQL_SCHEMA_TABLE				:	sql_template.SQLTemplate.buildSchemaTable(self.dbSchema, self.dbTableName),
							self.SQL_TABLE_INDEX_ID				:	self.buildTableIndexName("id"),
							self.SQL_TABLE_INDEX				:	self.buildTableIndexList(),
							self.SQL_CREATECOLUMS				:	self.buildColumnsList(),
							self.SQL_DATABASE_NAME				:	self.databaseName+"db",
							self.SQL_DATABASE_USER				:	self.databaseUser,
						}

	#Build the Table Columns
	def buildColumns(self, var, declared, param, sqltype):
		#"forename text NOT NULL,"
		return "\t{var} {sqltype} NOT NULL".format(var=var, sqltype=sqltype, dbSchema=self.dbSchema, dbTableName=self.dbTableName)

	def buildColumnsList(self):
		return (",\n".join(self.buildColumns(var, declared, param, sqltype) for (var, declared, param, sqltype) in self.sqlVariableList))



	#Build the Indexes
	def buildTableIndexName(self, var):
		return "idx_t{dbTableName}_{var}".format(var = var, dbTableName = self.dbTableName)

	def buildTableIndex(self, var, declared, param, sqltype):
		#"-- Index: idx_contact_id
		#-- DROP INDEX idx_contact_id;
		#CREATE INDEX idx_contact_id
		#	ON {SQL_SCHEMA_TABLE}
		#	USING btree (id);"
		return "-- Index: {buildTableIndexName}\n-- DROP INDEX {buildTableIndexName};\nCREATE INDEX {buildTableIndexName}\n\tON {SQL_SCHEMA_TABLE}\n\tUSING btree ({var});".format(var=var,
				SQL_SCHEMA_TABLE = sql_template.SQLTemplate.buildSchemaTable(self.dbSchema, self.dbTableName),
				buildTableIndexName = self.buildTableIndexName(var)
			)

	def buildTableIndexList(self):
		return ("\n\n".join(self.buildTableIndex(var, declared, param, sqltype) for (var, declared, param, sqltype) in self.sqlVariableList))
