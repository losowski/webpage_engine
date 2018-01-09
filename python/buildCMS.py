#!/usr/bin/python
# Autogenerate script to build the CGI classes for a CGI application

from build_page_queries import template_engine_data

def main():
	ted = template_engine_data.TemplateEngineData()
	ted.buildTemplates()

if __name__ == "__main__":
	main()
