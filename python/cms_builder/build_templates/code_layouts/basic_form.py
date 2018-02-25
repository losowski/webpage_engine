#!/usr/bin/python
#Basic HTML form engine
from string import Template

import basic_page

class BasicForm (basic_page.BasicPage):
	def __init__(self, variableList):
		basic_page.BasicPage.__init__(self, variableList)
		self.pagetype = "basicForm"

	def __del__(self):
		basic_page.BasicPage.__del__(self)
		pass

	def buildCGIFormDesign(self, fieldName, fieldTitle):
		return "\tdf->add_text_input(\"{fieldname}\", \"{fieldtitle}\", m_{fieldname});".format(fieldname = fieldName, fieldtitle = fieldTitle)
