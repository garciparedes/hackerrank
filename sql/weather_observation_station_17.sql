SELECT ROUND(long_w, 4)
FROM station
WHERE lat_n = (
    SELECT MIN(lat_n)
    FROM station
    WHERE 38.778 < lat_n
);
