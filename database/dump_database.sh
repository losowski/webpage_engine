#!/bin/sh
#psql -h localhost -d cmsdb -U cms -W
#Script to dump everything
#pg_dump Ft  -Ucms cmsdb > sql/cmsdb.tar
#Script to make entire DBi schema, create etc
pg_dump -svc --host=localhost -Ucms cmsdb > sql/cmsdb.sql
#Script to store data only
pg_dump -va --host=localhost --data-only -Ucms cmsdb > sql/cmsdb_data.sql
#Compress the data
tar -cvf sql/cmsdb.tar sql/cmsdb.sql sql/cmsdb_data.sql
#Exchange and Symbols only
pg_dump -va --host=localhost -Ucms cmsdb --data-only --table=cms_schema.symbol --table=cms_schema.exchange > sql/cmsdb_symbols.sql
