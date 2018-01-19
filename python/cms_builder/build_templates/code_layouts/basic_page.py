#!/usr/bin/python
#Basic HTML page
from string import Template
from cms_builder.build_templates import cpp_template

class BasicPage:
	def __init__(self, variableList):
		self.variableList = list()
		self.cgiCode = str()
		self.formatData(variableList)
		#Process Variables


	def __del__(self):
		pass

	def formatData(self, variableList):
		pass

	def buildPage(self):
		self.cgiCode = "// Undefined!"
		pass

	def getPage(self):
		return self.cgiCode
