#!/usr/bin/python
#Basic HTML form engine

import basic_page

class BasicForm (basic_page.BasicPage):
	def __init__(self, dataMap):
		basic_page.BasicPage.__init__(self, dataMap)

	def __del__(self):
		basic_page.BasicPage.__del__(self)
		pass

	def buildPage(self):
		pass
