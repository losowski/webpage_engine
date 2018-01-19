#!/usr/bin/python
#Basic HTML form engine
from string import Template

import basic_page

class BasicForm (basic_page.BasicPage):
	FIELDNAME	=	'FIELDNAME'
	FIELDTITLE	=	'FIELDTITLE'

	def __init__(self, variableList):
		basic_page.BasicPage.__init__(self, variableList)

	def __del__(self):
		basic_page.BasicPage.__del__(self)
		pass

	def formatData(self, variableList):
		for var in variableList:
			fieldName	= var
			fieldTitle	= ''.join(v.capitalize() for v in var.split('_'))
			self.variableList.append((fieldName, fieldTitle))


	def buildPage(self):
		for fieldName, fieldTitle in self.variableList:
			self.cgiCode += self.__formField(fieldName, fieldTitle)

	def __formField(self, fieldName, fieldTitle):
		temp = Template("df->add_text_input(\"$FIELDNAME\", \"$FIELDTITLE\", m_$FIELDNAME);\n\t")
		return temp.safe_substitute(FIELDNAME = fieldName , FIELDTITLE = fieldTitle)

