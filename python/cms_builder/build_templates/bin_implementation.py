#!/usr/bin/python
#Class to deal with the template for a Site Mapping Implementation

#Import relative to executing python file
import base_template
from cms_builder import const

from string import Template

class BinImplementation (base_template.BaseTemplate):
	CDN_MEDIA_PATH			= "CDN_MEDIA_PATH"
	CDN_JAVASCRIPT_PATH		= "CDN_JAVASCRIPT_PATH"
	CDN_CSS_PATH			= "CDN_CSS_PATH"
	LOGO_TOP_MENU			= "LOGO_TOP_MENU"

	def __init__(self, project, output, binaryName, cgiObjects ):
		base_template.BaseTemplate.__init__(self, "bin_site.cpp", "cpp/bin"+project+"/" + output)
		self.binaryName = binaryName
		self.cgiObjects = cgiObjects
		self.populateDataMap()
		pass

	def __del__(self):
		base_template.BaseTemplate.__del__(self)

	def populateDataMap(self):
		self.dataMap = {
						self.CDN_MEDIA_PATH				:	self.buildCDNMediaPath(),
						self.CDN_JAVASCRIPT_PATH		:	self.buildCDNJavaScriptPath(),
						self.CDN_CSS_PATH				:	self.buildCDNCSSPath(),
						self.LOGO_TOP_MENU				:	self.buildTopMenuLogo(),
					}

	def buildCDNMediaPath(self):
		return "page->setMediaPath(\"{cdnmediapath}\");".format(cdnmediapath = const.CDNMEDIAPATH)

	def buildCDNJavaScriptPath(self):
		return "page->setJavascriptPath(\"{cdnmediapath}\");".format(cdnmediapath = const.CDNJAVASCRIPTPATH)

	def buildCDNCSSPath(self):
		return "page->setCSSPath(\"{cdnmediapath}\");".format(cdnmediapath = const.CDNCSSPATH)

	def buildTopMenuLogo(self):
		#	page->TM_addLogo("doggo.png");
		return "page->TM_addLogo(\"{logoImage}.png\");".format(logoImage = self.binaryName)
