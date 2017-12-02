-- SELECT
-- INSERT
CREATE OR REPLACE FUNCTION demo_schema.pInsContact(
	p_forename				demo_schema.tcontact.forename%TYPE,
	p_happiness				demo_schema.tcontact.happiness%TYPE,
	p_created_date			demo_schema.tcontact.created_date%TYPE default localtimestamp
	) RETURNS bigint AS $$
DECLARE
	v_id					demo_schema.tcontact.id%TYPE;
BEGIN
	-- Insert data
	INSERT INTO
		demo_schema.tContact
		(
			forename,
			happiness,
			created_date
		)
	VALUES
		(
			p_forename,
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


-- Update
CREATE OR REPLACE FUNCTION demo_schema.pUpdContact(
	p_id					demo_schema.tcontact.id%TYPE,
	p_forename				demo_schema.tcontact.forename%TYPE default NULL,
	p_happiness				demo_schema.tcontact.happiness%TYPE default NULL,
	p_created_date			demo_schema.tcontact.created_date%TYPE default NULL
	) RETURNS bigint AS $$
DECLARE
	v_forename				demo_schema.tcontact.forename%TYPE;
	v_happiness				demo_schema.tcontact.happiness%TYPE;
	v_created_date			demo_schema.tcontact.created_date%TYPE;
BEGIN
	-- Get current Data and lock it
	SELECT FOR UPDATE
		COALESCE(p_forename, forename),
		COALESCE(p_happiness, happiness),
		COALESCE(p_created_date, created_date),
	INTO
		v_forename,
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
			forename,
			happiness,
			created_date
		)
	VALUES
		(
			v_forename,
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

-- Delete
CREATE OR REPLACE FUNCTION demo_schema.pDelContact(
	p_id					demo_schema.tcontact.id%TYPE
	) RETURNS bigint AS $$
DECLARE
	v_id					demo_schema.tcontact.id%TYPE;
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
