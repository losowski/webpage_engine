#!/usr/bin/python
#Class to deal with the template for a Site Mapping Implementation

#Import relative to executing python file
import base_template

from string import Template

class SiteImplementation (base_template.BaseTemplate):
	CGI_INCLUDE				=	"CGI_INCLUDE"
	CGI_DEFAULT_PAGE		=	"CGI_DEFAULT_PAGE"
	CGI_BUILD_SITE_PAGE_MAP	=	"CGI_BUILD_SITE_PAGE_MAP"
	CGI_MENU_ITEMS			=	"CGI_MENU_ITEMS"

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
							self.CGI_DEFAULT_PAGE				:	self.generateDefaultPage(),
							self.CGI_BUILD_SITE_PAGE_MAP		:	self.generateSitePageMapList(),
							self.CGI_MENU_ITEMS					:	self.generateCGIMenuItemList(),
						}
	"""
	Functions:
	1) Generate Page name (per input)
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

	#Class names
	def generateClassName(self, val):
		titleClassList = val.split('_')
		titleClassName = ''.join( name.capitalize() for name in titleClassList)
		return "{titleClassName}(m_page, m_cgi);".format(titleClassName = titleClassName)

	def generateDefaultPage(self):
		return self.generateClassName( self.cgiObjects[0].getFileName() )


	def generatePageString(self, val):
		return "\"{page}\"".format(page = val)

	def generateSitePageMap(self, val):
		page = self.generatePageString(val)
		classConstructor = self.generateClassName(val)
		#"elif (0 != m_cgipage.compare(page)) {
		# object = new $CGI_DEFAULT_PAGE
		#}"
		return "\telse if (0 != m_cgipage.compare({page})) {{\n\t\tobject = new {classConstructor}\n\t}}".format(page = page, classConstructor = classConstructor)

	def generateSitePageMapList(self):
		return ('\n'.join( self.generateSitePageMap( cgiObj.getFileName() ) for cgiObj in self.cgiObjects))

	#Menu Items
	def generateNameForMenu(self, val):
		return "\"{page}\"".format(page = val)

	def generateLinkForMenu(self, val):
		return "\"?page={page}\"".format(page = val)

	def generateTextForMenu(self, val):
		textList = val.split('_')
		page = ' '.join( name.capitalize() for name in textList)
		return "\"{page}\"".format(page=page)

	def generateCGIMenuItem(self, val):
		name = self.generateNameForMenu(val)
		link = self.generateLinkForMenu(val)
		text = self.generateTextForMenu(val)
		return "\t\tMenuItem({name}, {link}, {text})".format(name = name, link = link, text = text)

	def generateCGIMenuItemList(self):
		return (',\\\n'.join( self.generateCGIMenuItem( cgiObj.getFileName() ) for cgiObj in self.cgiObjects))

