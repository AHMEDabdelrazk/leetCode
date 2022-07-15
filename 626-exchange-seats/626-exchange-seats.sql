# Write your MySQL query statement below
SELECT 
CASE WHEN id%2=1 and id != (select COUNT(id) from Seat) THEN id+1
WHEN id%2=0 THEN  id-1
ELSE id
END AS id , student 
FROM Seat order by id ;