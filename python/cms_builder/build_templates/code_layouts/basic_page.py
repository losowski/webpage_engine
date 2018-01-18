#!/usr/bin/python
#Basic HTML page

class BasicPage::
	def __init__(self, dataMap):
		self.mDatamap = dataMap
		self.cgiCode = str()

	def __del__(self):
		pass

	def buildPage(self):
		pass

	def getPage(self):
		return self.cgiCode
