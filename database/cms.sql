--
-- Memories Database design
--

-- DROP TABLE events;
CREATE TABLE events
(
  uuid uuid NOT NULL,
  datetime timestamp without time zone NOT NULL,
  register text NOT NULL,
  value text NOT NULL,
  processed character(1) NOT NULL DEFAULT 'N'::bpchar,
  CONSTRAINT pk_events PRIMARY KEY (uuid)
)
WITH (
  OIDS=FALSE
);
ALTER TABLE events
  OWNER TO ai;

-- ALTER TABLE events DROP CONSTRAINT ck_events_processed;
ALTER TABLE events ADD CONSTRAINT ck_events_processed CHECK (processed = ANY (ARRAY['Y'::bpchar,'N'::bpchar]));

-- DROP INDEX idx_events_uuid;

CREATE INDEX idx_events_uuid
  ON events
  USING btree
  (uuid);

-- DROP INDEX idx_events_datetime;

CREATE INDEX idx_events_datetime
  ON events
  USING btree
  (datetime);

-- DROP INDEX idx_events_register;

CREATE INDEX idx_events_register
  ON events
  USING btree
  (register);

-- DROP INDEX idx_events_value;

CREATE INDEX idx_events_value
  ON events
  USING btree
  (value);


-- DROP INDEX idx_events_processed;

CREATE INDEX idx_events_processed
  ON events
  USING btree
  (processed COLLATE pg_catalog."default");

-- DROP SEQUENCE memories_id_seq;

CREATE SEQUENCE memories_id_seq
  INCREMENT 1
  MINVALUE 1
  MAXVALUE 9223372036854775807
  START 1
  CACHE 1;
ALTER TABLE memories_id_seq
  OWNER TO ai;


-- DROP TABLE memories;

CREATE TABLE memories
(
  id bigint NOT NULL DEFAULT nextval('ai.memories_id_seq'::regclass),
  true_id bigint,
  false_id bigint,
  comparator_value text,
  operator text,
  mini text,
  maxi text,
  value text,
  register text,
  pruned_count bigint DEFAULT 0,
  bias bigint DEFAULT 0,
  tolerance numeric DEFAULT 0,
  CONSTRAINT pk_memories PRIMARY KEY (id),
  CONSTRAINT fk_memories_false FOREIGN KEY (false_id)
      REFERENCES memories (id) MATCH SIMPLE
      ON UPDATE NO ACTION ON DELETE NO ACTION,
  CONSTRAINT fk_memories_true FOREIGN KEY (true_id)
      REFERENCES memories (id) MATCH SIMPLE
      ON UPDATE NO ACTION ON DELETE NO ACTION
)
WITH (
  OIDS=FALSE
);
ALTER TABLE memories
  OWNER TO ai;

-- ALTER TABLE ai.memories DROP CONSTRAINT "ck_memories_operator";
ALTER TABLE ai.memories ADD CONSTRAINT "ck_memories_operator" CHECK (operator = ANY (ARRAY['lt'::text, 'lte'::text, 'eq'::text, 'neq'::text, 'gt'::text, 'lte'::text, 'WT'::text, 'RD'::text]));

-- DROP INDEX idx_memories_a;
-- DROP INDEX idx_memories_bias;
-- DROP INDEX idx_memories_id;
-- DROP INDEX idx_memories_pruned_count;
-- DROP INDEX idx_memories_register;
-- DROP INDEX idx_memories_value;

CREATE INDEX idx_memories_value
  ON memories
  USING btree
  (value COLLATE pg_catalog."default");

CREATE INDEX idx_memories_register
  ON memories
  USING btree
  (register COLLATE pg_catalog."default");

CREATE INDEX idx_memories_pruned_count
  ON memories
  USING btree
  (pruned_count);

CREATE INDEX idx_memories_id
  ON memories
  USING btree
  (id);

CREATE INDEX idx_memories_bias
  ON memories
  USING btree
  (bias);

CREATE INDEX idx_memories_a
  ON memories
  USING btree
  (a COLLATE pg_catalog."default");


-- DROP TABLE pruned_memories;

CREATE TABLE pruned_memories
(
  id bigserial NOT NULL,
  true_id bigint,
  false_id bigint,
  a text,
  operator text,
  b text,
  value text,
  register text,
  pruned_count bigint DEFAULT 0,
  bias bigint DEFAULT 0,
  CONSTRAINT pk_pruned_memories PRIMARY KEY (id)
)
WITH (
  OIDS=FALSE
);
ALTER TABLE pruned_memories
  OWNER TO ai;

-- DROP INDEX idx_pruned_memories_id;
-- DROP INDEX idx_pruned_memories_register;
-- DROP INDEX idx_pruned_memories_value;

CREATE INDEX idx_pruned_memories_value
  ON pruned_memories
  USING btree
  (value COLLATE pg_catalog."default");

CREATE INDEX idx_pruned_memories_register
  ON pruned_memories
  USING btree
  (register COLLATE pg_catalog."default", id);

CREATE INDEX idx_pruned_memories_id
  ON pruned_memories
  USING btree
  (id);
