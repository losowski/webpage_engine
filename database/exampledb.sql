
--
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
CREATE SCHEMA IF NOT EXISTS "demo_schema" AUTHORIZATION demo;
--
-- Grant privileges
--
GRANT ALL PRIVILEGES ON demodb TO demo;

-- SCRIPT BEGIN: set up connection and schema
\connect demodb
set schema 'demo_schema';
-- SCRIPT END
-- Table: "tContact"
-- DROP TABLE "tContact";
CREATE TABLE "demo_schema.tContact"
(
  id bigserial NOT NULL,
  forename text NOT NULL,
  happiness numeric	NOT NULL,
  CONSTRAINT pk_contact PRIMARY KEY (id)
)
WITH (
  OIDS=FALSE
);
ALTER TABLE "demo_schema.tContact"
  OWNER TO demo;

-- Index: idx_contact_id
-- DROP INDEX idx_contact_id;
CREATE INDEX idx_contact_id
  ON "demo_schema.tContact"
  USING btree
  (id);
