#!/usr/bin/python
#Class to deal with the template for creating the database table

#Import relative to executing python file
import sql_template

from string import Template

class SQLCreateTable (sql_template.SQLTemplate):
	def __init__(self, dbSchema, dbTableName, variableList):
		sql_template.SQLTemplate.__init__(self, "stored_procedure.sql", dbTableName+"_procedure.sql", dbSchema, dbTableName, variableList)
		pass

	def __del__(self):
		sql_template.SQLTemplate.__del__(self)

	def populateDataMap(self):
		#Overload to support dict objects as variables
		pass



