SELECT
    IF(grades.grade > 7, students.name, "NULL") AS name,
    grades.grade,
    students.marks
FROM
    students,
    grades
WHERE
    grades.min_mark <= students.marks AND
    students.marks <= grades.max_mark
ORDER BY
    grades.grade DESC,
    name ASC,
    students.marks ASC;
