#!/usr/bin/python
#Class to deal with the template for a CPP header

#Import relative to executing python file
from cms_builder import template_engine_base
from build_templates import base_template

class TemplateEngineSQL (template_engine_base.TemplateEngineBase):
	def __init__(self):
		template_engine_base.TemplateEngineBase.__init__(self)
		self.database = dict()
		self.cgiBinaryName	=	"web"
		self.databaseName	=	"site"
		self.databaseUser	=	"site"
		#Set the Data

	def __del__(self):
		template_engine_base.TemplateEngineBase.__del__(self)

#	def buildTemplates(self):
	def getData(self):
		pass
