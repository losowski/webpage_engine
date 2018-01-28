#!/usr/bin/python
#Class to deal with the template for a CPP header

#Import relative to executing python file
from cms_builder import template_engine_base
from build_templates import base_template
from build_templates import cgi_files

class TemplateEngineData (template_engine_base.TemplateEngineBase):
	def __init__(self):
		template_engine_base.TemplateEngineBase.__init__(self)
		#Set the Data
		self.cgiBinaryName	=	"webcms"
		self.cgiObjects 	=	{ cgi_files.CGIFiles ("demo_page", None, "demo_schema", "contact", None, variableList = [
																												('forename',"text"),
																												('happiness',"text"),
																												('created_date',"text")
																																		]),
								}

	def __del__(self):
		template_engine_base.TemplateEngineBase.__del__(self)

#	def buildTemplates(self):
#	def getData(self):
