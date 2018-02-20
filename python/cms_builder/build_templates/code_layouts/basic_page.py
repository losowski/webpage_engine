#!/usr/bin/python
#Basic HTML page
from string import Template

class BasicPage:
	def __init__(self, variableList):
		self.pagetype = "basicPage"

	def __del__(self):
		pass

	def getPageType(self):
		return self.pagetype

	def buildCGIFormDesign(self, fieldName, fieldTitle):
		pass
