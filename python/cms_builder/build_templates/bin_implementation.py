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
	LOGO_LEFT_HAND_MENU		= "LOGO_LEFT_HAND_MENU"

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
						self.LOGO_LEFT_HAND_MENU		:	self.buildLeftHandMenuLogo(),
					}

	def buildCDNMediaPath(self):
		path = ""
		if (None != const.CDNMEDIAPATH):
			path = "page->setMediaPath(\"{cdnmediapath}\");".format(cdnmediapath = const.CDNMEDIAPATH)
		return path

	def buildCDNJavaScriptPath(self):
		path = ""
		if (None != const.CDNMEDIAPATH):
			cdnPath = const.CDNMEDIAPATH
			if (None != const.CDNJAVASCRIPTPATH):
				cdnPath = "/".join ((const.CDNMEDIAPATH, const.CDNJAVASCRIPTPATH))
			path = "page->setJavascriptPath(\"{cdnmediapath}\");".format(cdnmediapath = cdnPath)
		return path

	def buildCDNCSSPath(self):
		path = ""
		if (None != const.CDNMEDIAPATH):
			cdnPath = const.CDNMEDIAPATH
			if (None != const.CDNCSSPATH):
				cdnPath = "/".join ((const.CDNMEDIAPATH, const.CDNCSSPATH))
			path = "page->setCSSPath(\"{cdnmediapath}\");".format(cdnmediapath = cdnPath)
		return path

	def buildTopMenuLogo(self):
		#	page->TM_addLogo("doggo.png");
		return "page->TM_addLogo(\"{logoImage}.png\");".format(logoImage = self.binaryName)

	def buildLeftHandMenuLogo(self):
		#	page->LHM_addLogo("doggo2.png");
		return "page->LHM_addLogo(\"{logoImage}_lhm.png\");".format(logoImage = self.binaryName)
