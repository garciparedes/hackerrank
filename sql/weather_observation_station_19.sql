SELECT ROUND(SQRT(POW(p1.lat_n - p2.lat_n, 2) +
                  POW(p1.long_w - p2.long_w, 2)), 4)
FROM
    (
        SELECT p1_lat.lat_n, p1_long.long_w
        FROM (
            SELECT lat_n
            FROM station
            WHERE lat_n = (
                SELECT MIN(lat_n)
                FROM station
            )
        ) AS p1_lat,
        (
            SELECT long_w
            FROM station
            WHERE long_w = (
                SELECT MIN(long_w)
                FROM station
            )
        ) AS p1_long
    ) AS p1,
    (
        SELECT p2_lat.lat_n, p2_long.long_w
        FROM (
            SELECT lat_n
            FROM station
            WHERE lat_n = (
                SELECT MAX(lat_n)
                FROM station
            )
        ) AS p2_lat,
        (
            SELECT long_w
            FROM station
            WHERE long_w = (
                SELECT MAX(long_w)
                FROM station
            )
        ) AS p2_long
    ) AS p2;
