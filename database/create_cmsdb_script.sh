#!/bin/sh
#
# Script to read back backups of the database
#
#Create a blank file
echo "" > create_tradedb.sql

#Setup the basics of the database
cat cms_user.sql >> create_tradedb.sql
cat cms_database.sql >> create_tradedb.sql
cat cms_grant.sql >> create_tradedb.sql

#Setup Database and schema
# Triple backslash to work with debian (ignores arguments)
echo "-- SCRIPT BEGIN: set up connection and schema" >> create_tradedb.sql
echo "\\\connect cmsdb" >> create_tradedb.sql
echo "set schema 'cms_schema';" >> create_tradedb.sql
echo "-- SCRIPT END" >> create_tradedb.sql

#Write the data into the system
cat cmsdb.sql >> create_tradedb.sql
cat cmsdb_data.sql >> create_tradedb.sql

#Modify the schema so we load the correct one
#sed -iv 's/cms_schema/cmsdb.cms_schema/' create_tradedb.sql
