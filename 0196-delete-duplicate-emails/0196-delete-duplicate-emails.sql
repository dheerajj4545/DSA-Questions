# Write your MySQL query statement below
DELETE p1 FROM
person AS p1 INNER JOIN
person AS p2 ON
p1.email=p2.email WHERE
p1.id>p2.id;