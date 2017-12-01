-- SELECT
-- INSERT
CREATE OR REPLACE FUNCTION demo_schema.pInsContact(
	p_name					demo_schema.tContact.name%TYPE,
	p_happiness				demo_schema.tContact.happiness%TYPE,
	p_created_date			demo_schema.tContact.created_date%TYPE default localtimestamp
	) RETURNS bigint AS $$
DECLARE
	v_id					demo_schema.tContact.id%TYPE;
BEGIN
	-- Insert data
	INSERT INTO
		demo_schema.tContact
		(
			name,
			happiness,
			created_date
		)
	VALUES
		(
			p_name,
			p_happiness,
			p_created_date
		)
	;
	-- Return ID
	SELECT
		*
	INTO
		v_id
	FROM
		LASTVAL()
	;
	RETURN v_id;
END;
$$ LANGUAGE plpgsql;


﻿-- Update
CREATE OR REPLACE FUNCTION demo_schema.pUpdContact(
	p_id					demo_schema.tContact.id%TYPE,
	p_name					demo_schema.tContact.name%TYPE default NULL,
	p_happiness				demo_schema.tContact.happiness%TYPE default NULL,
	p_created_date			demo_schema.tContact.created_date%TYPE default NULL
	) RETURNS bigint AS $$
DECLARE
	v_id					demo_schema.tContact.id%TYPE;
	v_name					demo_schema.tContact.name%TYPE;
	v_happiness				demo_schema.tContact.happiness%TYPE;
	v_created_date			demo_schema.tContact.created_date%TYPE;
BEGIN
	-- Get current Data and lock it
	SELECT FOR UPDATE
		COALESCE(p_name, name),
		COALESCE(p_happiness, happiness),
		COALESCE(p_created_date, created_date),
	INTO
		v_id,
		v_name,
		v_happiness,
		v_created_date
	FROM
		demo_schema.tContact
	WHERE
		id = p_id
	;

	-- Update data
	UPDATE
		demo_schema.tContact
	SET
		(
			name,
			happiness,
			created_date
		)
	VALUES
		(
			v_name,
			v_happiness,
			v_created_date
		)
	WHERE
		id = p_id
	;
	-- Return ID
	RETURN p_id;
END;
$$ LANGUAGE plpgsql;

﻿-- Delete
CREATE OR REPLACE FUNCTION demo_schema.pDelContact(
	p_id					demo_schema.tContact.id%TYPE
	) RETURNS bigint AS $$
DECLARE
	v_id					demo_schema.tContact.id%TYPE;
BEGIN
	-- Delete data
	DELETE FROM
		demo_schema.tContact
	WHERE
		id = p_id
	;
	-- Return ID
	RETURN p_id;
END;
$$ LANGUAGE plpgsql;
