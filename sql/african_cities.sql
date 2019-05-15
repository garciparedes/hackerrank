SELECT
    city.name
FROM
    city,
    country
WHERE
    country.countrycode = city.code AND
    country.continent LIKE 'Africa';
