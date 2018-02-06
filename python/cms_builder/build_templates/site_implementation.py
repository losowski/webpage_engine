#!/usr/bin/python
#Class to deal with the template for a Site Mapping Implementation

#Import relative to executing python file
import base_template

from string import Template

class SiteImplementation (base_template.BaseTemplate):
	CGI_INCLUDE			=	"CGI_INCLUDE"
	CGI_DEFAULT_PAGE	=	"CGI_DEFAULT_PAGE"
	CGI_BUILD_SITE_MAP	=	"CGI_BUILD_SITE_MAP"
	CGI_MENU_ITEMS		=	"CGI_MENU_ITEMS"

	def __init__(self, project, output, binaryName, cgiObjects ):
		base_template.BaseTemplate.__init__(self, "site.cpp", "cpp/lib"+project+"/" + output)
		self.binaryName = binaryName
		self.cgiObjects = cgiObjects
		self.populateDataMap()
		pass

	def __del__(self):
		base_template.BaseTemplate.__del__(self)

	def populateDataMap(self):
		#Pass do nothing
		CGI_DEFAULT_PAGE
		pass

	def populateDataMap(self):
		self.dataMap = {
							self.CGI_INCLUDE					:	self.generateIncludeList(),
							self.CGI_DEFAULT_PAGE				:	self.generateIncludeList(),
							self.CGI_BUILD_SITE_MAP				:	self.generateIncludeList(),
							self.CGI_MENU_ITEMS					:	self.generateIncludeList(),
						}
	"""
	Functions:
	1) Generate Key name (per input)
	2) Generate Class names
	3) Generate: "case (VALUE):
					object = new CLASSNAME (from function 2);
					break;
	4)
	"""
	#Includes
	def generateInclude(self, val):
		return "#include \"{val}.hpp\"".format(val = val)

	def generateIncludeList(self):
		return ('\n'.join( self.generateInclude( cgiObj.getFileName() ) for cgiObj in self.cgiObjects))

	def generateClassName(self, val):
		return "{val}".format(val = val)

	def generateKeyString(self, val):
		return "{key}".format(val = val)

#	def defaultPage
