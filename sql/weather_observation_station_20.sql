SET @pos = 0;
SELECT ROUND(lat_n, 4)
FROM station
WHERE lat_n = (
    SELECT s.lat_n
    FROM (
        SELECT lat_n, @pos := @pos + 1 AS pos
        FROM station
        ORDER BY lat_n DESC
    ) AS s,
    (
        SELECT COUNT(*) AS cnt
        FROM station
    ) AS c
    WHERE s.pos = CEIL(c.cnt / 2)
);

        
