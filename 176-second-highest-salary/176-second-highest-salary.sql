# Write your MySQL query statement below
SELECT IF(
(SELECT DISTINCT(salary) FROM Employee
ORDER BY salary DESC LIMIT 1,1) = 1, NULL,
(SELECT DISTINCT(salary) FROM Employee
ORDER BY salary DESC LIMIT 1,1 ))
AS 'SecondHighestSalary';