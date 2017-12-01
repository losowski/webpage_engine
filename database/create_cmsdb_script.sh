#!/bin/sh
#
# Script to read back backups of the database
#
#Create a blank file
echo "" > create_cmsdb.sql

#Setup the basics of the database
cat cms_user.sql >> create_cmsdb.sql
cat cms_database.sql >> create_cmsdb.sql
cat cms_grant.sql >> create_cmsdb.sql

#Setup Database and schema
# Triple backslash to work with debian (ignores arguments)
echo "-- SCRIPT BEGIN: set up connection and schema" >> create_cmsdb.sql
echo "\\\connect cmsdb" >> create_cmsdb.sql
echo "--\n-- Create the schema\n--" >> create_cmsdb.sql
echo "CREATE SCHEMA IF NOT EXISTS cms_schema AUTHORIZATION cms;\n" >> create_cmsdb.sql
echo "set schema 'cms_schema';" >> create_cmsdb.sql
echo "-- SCRIPT END" >> create_cmsdb.sql
#Write the data into the system
cat cmsdb.sql >> create_cmsdb.sql
cat cmsdb_data.sql >> create_cmsdb.sql

#Write in the Stored procedures

#Modify the schema so we load the correct one
#sed -iv 's/cms_schema/cmsdb.cms_schema/' create_cmsdb.sql
