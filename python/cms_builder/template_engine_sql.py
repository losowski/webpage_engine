#!/usr/bin/python
#Class to deal with the template for a CPP header

#Import relative to executing python file
from build_page_queries import template_engine_base
from build_templates import cpp_template

class TemplateEngineSQL (template_engine_base.TemplateEngineBase):
	def __init__(self):
		template_engine_base.TemplateEngineBase.__init__(self)
		#Set the Data

	def __del__(self):
		template_engine_base.TemplateEngineBase.__del__(self)

	def getClasses(self):
		pass

	def getClassFields(self, className):
		pass
