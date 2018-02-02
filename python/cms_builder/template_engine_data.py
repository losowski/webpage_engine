#!/usr/bin/python
#Class to deal with the template for a CPP header

#Import relative to executing python file
from cms_builder import const
from cms_builder import template_engine_base
from build_templates import base_template
from build_templates import cgi_files

class TemplateEngineData (template_engine_base.TemplateEngineBase):
	def __init__(self):
		template_engine_base.TemplateEngineBase.__init__(self)
		#Set the Data
		self.cgiBinaryName	=	"webcms"
		self.cgiObjects 	=	{ cgi_files.CGIFiles (self.cgiBinaryName, "demo_page", None, "demo_schema", "contact", None, variableList = [
																												('forename',		const.TYPE_SQL_TEXT),
																												('happiness',		const.TYPE_SQL_INT),
																												('created_date',	const.TYPE_SQL_DATE)
																																		]),
								}

	def __del__(self):
		template_engine_base.TemplateEngineBase.__del__(self)

#	def buildTemplates(self):
#	def getData(self):
