#!/usr/bin/python
#Class to deal with the template for a CPP header

#Import relative to executing python file
from cms_builder import template_engine_base
from build_templates import cpp_template

class TemplateEngineData (template_engine_base.TemplateEngineBase):
	def __init__(self):
		template_engine_base.TemplateEngineBase.__init__(self)
		#Set the Data
		self.database =	{	"demo_page" :	{	cpp_template.CPPTemplate.CPP_CLASS : "demo_page",
												cpp_template.CPPTemplate.VARIABLE_LIST: ['id', 'forename', 'happiness', 'created_date'],
											}
						}

	def __del__(self):
		template_engine_base.TemplateEngineBase.__del__(self)

#	def buildTemplates(self):
#	def getData(self):
