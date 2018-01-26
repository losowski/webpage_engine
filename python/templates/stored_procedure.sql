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
	IN	p_id					demo_schema.tcontact.id%TYPE default NULL,
$SQL_PARAMETER
	) RETURNS bigint AS $$
DECLARE
	v_id					demo_schema.tcontact.id%TYPE := NULL;
$SQL_DECLARED
BEGIN
	-- Get current Data and lock it
	SELECT
		id,
		COALESCE(p_forename, forename),
		COALESCE(p_happiness, happiness),
		COALESCE(p_created_date, created_date)
	INTO
		v_id,
		v_forename,
		v_happiness,
		v_created_date
	FROM
		demo_schema.tContact
	WHERE
		id = p_id
	FOR UPDATE
	;
	-- Compare values for each entry
	IF v_forename != p_forename AND p_forename IS NOT NULL THEN
		v_forename := p_forename;
	END IF;
	IF v_happiness != p_happiness AND p_happiness IS NOT NULL THEN
		v_happiness := p_happiness;
	END IF;
	IF v_created_date != p_created_date AND p_created_date IS NOT NULL THEN
		v_created_date := p_created_date;
	END IF;

	-- Update data
	UPDATE
		demo_schema.tContact
	SET
			forename = v_forename,
			happiness = v_happiness,
			created_date = v_created_date
	WHERE
		id = v_id
	;
	-- WHEN no_data_found THEN
	IF v_id IS NULL THEN

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
	END IF;
	-- Return ID
	RETURN v_id;
END;
$$ LANGUAGE plpgsql
CALLED ON NULL INPUT
;













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
