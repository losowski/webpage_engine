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
$SQL_COMPAREVALUES4UPDATE
	-- Update data
	UPDATE
		$SQL_SCHEMA_TABLE
	SET
$SQL_UPDATESETVALUE
	WHERE
		id = v_id
	;
	-- WHEN no_data_found THEN
	IF v_id IS NULL THEN

		-- Insert data
		INSERT INTO
			$SQL_SCHEMA_TABLE
			(
$SQL_VARLIST
			)
		VALUES
			(
$SQL_PARAMLIST
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
