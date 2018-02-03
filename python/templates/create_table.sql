--
-- psql -h localhost -U demo -d demodb -W
-- Create the demo user for the demodb
--
CREATE ROLE demo LOGIN NOSUPERUSER INHERIT CREATEDB CREATEROLE NOREPLICATION PASSWORD 'demodb';
--
-- Create the database
--
CREATE DATABASE demodb OWNER demo;
--
-- Create the schema
--
CREATE SCHEMA IF NOT EXISTS $SQL_SCHEMA_TABLE AUTHORIZATION demo;
--
-- Grant privileges
--
GRANT ALL PRIVILEGES ON demodb TO demo;

-- SCRIPT BEGIN: set up connection and schema
\connect demodb
set schema $SQL_SCHEMA_TABLE;
-- SCRIPT END
-- Table: "$SQL_SCHEMA_TABLE"
-- DROP TABLE "$SQL_SCHEMA_TABLE";
CREATE TABLE $SQL_SCHEMA_TABLE
(
	id bigserial NOT NULL,
$SQL_CREATECOLUMS
	CONSTRAINT pk_contact PRIMARY KEY (id)
)
WITH (
	OIDS=FALSE
);
ALTER TABLE $SQL_SCHEMA_TABLE
	OWNER TO demo;

-- Index: $TABLE_INDEX_ID
-- DROP INDEX $TABLE_INDEX_ID;
CREATE INDEX $TABLE_INDEX_ID
  ON $SQL_SCHEMA_TABLE
  USING btree
  (id);

$SQL_TABLE_INDEX
