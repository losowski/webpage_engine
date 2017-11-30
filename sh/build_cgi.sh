#!/bin/sh
#
# Build the CGI files (or local file)
#
echo "Loading CGI files"
## lib
cp -v lib/*.so /var/www/cgi-bin/.
ldconfig
## bin
cp -v bin/*.cgi /var/www/cgi-bin/.
echo "FINISHED"
