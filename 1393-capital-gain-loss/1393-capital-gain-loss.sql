# Write your MySQL query statement below
select stock_name, sum(case when operation = 'Buy' then 0-price else price end) capital_gain_loss
from stocks group by stock_name
order by sum(case when operation = 'Buy' then 0-price else price end) desc