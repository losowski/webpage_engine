-- Table: cms_schema.tCMSSite
-- DROP TABLE cms_schema.tCMSSite;
CREATE TABLE cms_schema.tCMSSite
(
  id bigserial NOT NULL,
  site_name text NOT NULL,
  CONSTRAINT pk_cmssite PRIMARY KEY (id)
)
WITH (
  OIDS=FALSE
);
ALTER TABLE cms_schema.tCMSSite
  OWNER TO cms;

-- Index: idx_cmssite_id
-- DROP INDEX idx_cmssite_id;
CREATE INDEX idx_cmssite_id
  ON cms_schema.tCMSSite
  USING btree
  (id);

-- Table: cms_schema.tCMSPage
-- DROP TABLE cms_schema.tCMSPage;
CREATE TABLE cms_schema.tCMSPage
(
  id bigserial NOT NULL,
  page_name text NOT NULL,
  class text NOT NULL,
  site_id bigint NOT NULL,
  CONSTRAINT pk_cmspage PRIMARY KEY (id),
  CONSTRAINT fk_cmspage_site_id FOREIGN KEY (site_id)
      REFERENCES cms_schema.tCMSSite (id) MATCH SIMPLE
      ON UPDATE NO ACTION ON DELETE NO ACTION
)
WITH (
  OIDS=FALSE
);
ALTER TABLE cms_schema.tCMSPage
  OWNER TO cms;

-- Index: idx_cmspage_page_name
-- DROP INDEX idx_cmspage_page_name;
CREATE INDEX idx_cmspage_page_name
  ON cms_schema.tCMSPage
  USING btree
  (page_name COLLATE pg_catalog."default");

-- Index: idx_cmspage_site_id
-- DROP INDEX idx_cmspage_site_id;
CREATE INDEX idx_cmspage_site_id
  ON cms_schema.tCMSPage
  USING btree
  (site_id);

-- Foreign Key: fk_cmspage_site_id
-- ALTER TABLE cms_schema.tCMSPage DROP CONSTRAINT fk_cmspage_site_id;
ALTER TABLE cms_schema.tCMSPage
  ADD CONSTRAINT fk_cmspage_site_id FOREIGN KEY (site_id)
      REFERENCES cms_schema.tCMSSite (id) MATCH SIMPLE
      ON UPDATE NO ACTION ON DELETE NO ACTION;

-- Table: cms_schema.tCMSField

-- DROP TABLE cms_schema.tCMSField;

CREATE TABLE cms_schema.tCMSField
(
  id bigserial NOT NULL,
  page_id bigint NOT NULL,
  field_name text NOT NULL,
  table_name text NOT NULL,
  column_name text NOT NULL,
  CONSTRAINT pk_cmsfield PRIMARY KEY (id),
  CONSTRAINT fk_field_page FOREIGN KEY (page_id)
      REFERENCES cms_schema.tCMSPage (id) MATCH SIMPLE
      ON UPDATE NO ACTION ON DELETE NO ACTION
)
WITH (
  OIDS=FALSE
);
ALTER TABLE cms_schema.tCMSField
  OWNER TO cms;

-- Index: idx_field
-- DROP INDEX idx_field;
CREATE INDEX idx_field
  ON cms_schema.tCMSField
  USING btree
  (id);

-- Index: idx_field_page
-- DROP INDEX idx_field_page;
CREATE INDEX idx_field_page
  ON cms_schema.tCMSField
  USING btree
  (page_id);
