SELECT
    id, age, coins_needed, power
FROM
    wands w LEFT JOIN wands_property p ON
        w.code = p.code
WHERE
    is_evil = 0 AND
    (age, power, coins_needed) IN (
        SELECT
            age, power, min(coins_needed)
        FROM
            wands w LEFT JOIN wands_property p ON
                w.code = p.code
        GROUP BY
            age, power
    )
ORDER BY
    power DESC, age DESC;
