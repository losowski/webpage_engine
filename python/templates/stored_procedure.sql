-- Update-Insert
CREATE OR REPLACE FUNCTION $SQL_STOREDPROCNAME(
	IN	p_id					$SQL_SCHEMA_TABLE.id%TYPE default NULL,
$SQL_PARAMETER
	) RETURNS bigint AS $$
DECLARE
	v_id					$SQL_SCHEMA_TABLE.id%TYPE := NULL;
$SQL_DECLARED
BEGIN
	-- Get current Data and lock it
	SELECT
		id,
$SQL_FIELDSSELECT4UPDATE
	INTO
		v_id,
$SQL_DECLARESELECT4UPDATE
	FROM
		$SQL_SCHEMA_TABLE
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
		$SQL_SCHEMA_TABLE
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
			$SQL_SCHEMA_TABLE
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
