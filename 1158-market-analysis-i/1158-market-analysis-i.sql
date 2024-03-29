# Write your MySQL query statement below
select user_id as buyer_id,join_date,ifnull(orders_in_2019,0) as orders_in_2019
from users u
left join (
select buyer_id,count(buyer_id) as orders_in_2019 from orders
where order_date between '2019-01-01' and '2019-12-31' group by buyer_id)
c on u.user_id = c.buyer_id