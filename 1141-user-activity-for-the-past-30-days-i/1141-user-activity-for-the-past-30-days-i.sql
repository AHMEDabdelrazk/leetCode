# Write your MySQL query statement below
SELECT activity_date as day,
COUNT(*) as active_users
FROM (SELECT DISTINCT user_id, activity_date FROM Activity WHERE DATEDIFF('2019-07-27', activity_date) < 30 AND activity_date < '2019-07-27') as x
GROUP BY activity_date