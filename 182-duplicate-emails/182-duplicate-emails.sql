# Write your MySQL query statement below
SELECT a.email AS Email
FROM `person` AS a, `person` AS b
WHERE a.id!=b.id AND a.email=b.email
GROUP BY Email;