-- SELECT
CREATE OR REPLACE FUNCTION demo_schema.pSelContact(
	p_id				demo_schema.tcontact.id%TYPE
	) RETURNS RECORD AS $$
DECLARE
	v_rowdata					RECORD;
BEGIN
	-- Select data
	SELECT
		id,
		forename,
		happiness,
		created_date
	INTO
		v_rowdata
	FROM
		demo_schema.tContact
	WHERE
		id = p_id
	;
	-- Return Data
 	RETURN v_rowdata;
END;
$$ LANGUAGE plpgsql;






-- Update-Insert
CREATE OR REPLACE FUNCTION demo_schema.pInsUpdContact(
	p_id					demo_schema.tcontact.id%TYPE,
	p_forename				demo_schema.tcontact.forename%TYPE default NULL,
	p_happiness				demo_schema.tcontact.happiness%TYPE default NULL,
	p_created_date			demo_schema.tcontact.created_date%TYPE default NULL
	) RETURNS bigint AS $$
DECLARE
	v_id					demo_schema.tcontact.id%TYPE;
	v_forename				demo_schema.tcontact.forename%TYPE;
	v_happiness				demo_schema.tcontact.happiness%TYPE;
	v_created_date			demo_schema.tcontact.created_date%TYPE;
BEGIN
	BEGIN
	-- Get current Data and lock it
		SELECT
			COALESCE(p_forename, forename),
			COALESCE(p_happiness, happiness),
			COALESCE(p_created_date, created_date)
		INTO
			v_forename,
			v_happiness,
			v_created_date
		FROM
			demo_schema.tContact
		WHERE
			id = p_id
		FOR UPDATE
		;
	-- Set v_id
		v_id := p_id;
	-- Compare values
	IF v_forname != p_forename OR
		v_happiness != p_happiness OR
		v_created_date != p_created_date THEN
		-- Update data
			UPDATE
				demo_schema.tContact
			SET
					forename = v_forename,
					happiness = v_happiness,
					created_date = v_created_date
			WHERE
				id = p_id
			;
	END IF;
	EXCEPTION
		WHEN no_data_found THEN
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
	END;

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
