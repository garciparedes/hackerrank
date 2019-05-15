SELECT e1.earnings, e1.cnt
FROM (
    SELECT  e2.earnings, COUNT(e2.earnings) AS cnt
    FROM (
        SELECT salary * months AS earnings
        FROM employee
    ) AS e2
    GROUP BY e2.earnings
) AS e1
WHERE e1.earnings = (
    SELECT MAX(e2.earnings)
    FROM (
        SELECT salary * months AS earnings
        FROM employee
    ) AS e2
);
