-- Table: "tCMSSite"
-- DROP TABLE "tCMSSite";
CREATE TABLE "tCMSSite"
(
  id bigserial NOT NULL,
  site_name text NOT NULL,
  CONSTRAINT pk_cmssite PRIMARY KEY (id)
)
WITH (
  OIDS=FALSE
);
ALTER TABLE "tCMSSite"
  OWNER TO cms;

-- Index: idx_cmssite_id
-- DROP INDEX idx_cmssite_id;
CREATE INDEX idx_cmssite_id
  ON "tCMSSite"
  USING btree
  (id);

-- Table: "tCMSPage"
-- DROP TABLE "tCMSPage";
CREATE TABLE "tCMSPage"
(
  id bigserial NOT NULL,
  page_name text NOT NULL,
  class text NOT NULL,
  site_id bigint NOT NULL,
  CONSTRAINT pk_cmspage PRIMARY KEY (id),
  CONSTRAINT fk_cmspage_site_id FOREIGN KEY (site_id)
      REFERENCES "tCMSSite" (id) MATCH SIMPLE
      ON UPDATE NO ACTION ON DELETE NO ACTION
)
WITH (
  OIDS=FALSE
);
ALTER TABLE "tCMSPage"
  OWNER TO cms;

-- Index: idx_cmspage_page_name
-- DROP INDEX idx_cmspage_page_name;
CREATE INDEX idx_cmspage_page_name
  ON "tCMSPage"
  USING btree
  (page_name COLLATE pg_catalog."default");

-- Index: idx_cmspage_site_id
-- DROP INDEX idx_cmspage_site_id;
CREATE INDEX idx_cmspage_site_id
  ON "tCMSPage"
  USING btree
  (site_id);

-- Foreign Key: fk_cmspage_site_id
-- ALTER TABLE "tCMSPage" DROP CONSTRAINT fk_cmspage_site_id;
ALTER TABLE "tCMSPage"
  ADD CONSTRAINT fk_cmspage_site_id FOREIGN KEY (site_id)
      REFERENCES "tCMSSite" (id) MATCH SIMPLE
      ON UPDATE NO ACTION ON DELETE NO ACTION;

-- Table: "tCMSField"

-- DROP TABLE "tCMSField";

CREATE TABLE "tCMSField"
(
  id bigserial NOT NULL,
  page_id bigint NOT NULL,
  field_name text NOT NULL,
  table_name text NOT NULL,
  column_name text NOT NULL,
  CONSTRAINT pk_cmsfield PRIMARY KEY (id),
  CONSTRAINT fk_field_page FOREIGN KEY (page_id)
      REFERENCES "tCMSPage" (id) MATCH SIMPLE
      ON UPDATE NO ACTION ON DELETE NO ACTION
)
WITH (
  OIDS=FALSE
);
ALTER TABLE "tCMSField"
  OWNER TO postgres;

-- Index: idx_field
-- DROP INDEX idx_field;
CREATE INDEX idx_field
  ON "tCMSField"
  USING btree
  (id);

-- Index: idx_field_page
-- DROP INDEX idx_field_page;
CREATE INDEX idx_field_page
  ON "tCMSField"
  USING btree
  (page_id);
