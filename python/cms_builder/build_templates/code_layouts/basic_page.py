#!/usr/bin/python
#Basic HTML page
from string import Template

class BasicPage:
	def __init__(self, variableList):
		self.variableList = variableList
		self.cgiCode = str()
		self.formattedData = list()
		#Process Variables
		self.pagetype = "basicPage"

	def __del__(self):
		pass

	def getPageType(self):
		return self.pagetype

	def formatData(self):
		pass

	def buildPage(self):
		self.cgiCode = "// Undefined!"
		pass

	def getPage(self):
		return self.cgiCode
