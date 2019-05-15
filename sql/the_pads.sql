SELECT CONCAT(name, "(", UPPER(SUBSTRING(occupation, 1, 1)),")") as t
FROM occupations
ORDER BY t ASC;

SELECT CONCAT("There are a total of ", COUNT(*), " ", LOWER(occupation), "s." ) as t
FROM occupations
GROUP BY occupation
ORDER BY t ASC;
