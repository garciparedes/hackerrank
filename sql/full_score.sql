SELECT
    h.hacker_id,
    h.name
FROM
    hackers h,
    (
        SELECT
            s.hacker_id,
            COUNT(*) as cnt
        FROM
            submissions s,
            challenges c,
            difficulty d
        WHERE
            s.challenge_id = c.challenge_id AND
            c.difficulty_level = d.difficulty_level AND
            d.score = s.score
        GROUP BY s.hacker_id
    ) AS q
WHERE q.cnt > 1 AND
    h.hacker_id = q.hacker_id
ORDER BY
    q.cnt DESC,
    q.hacker_id ASC;
