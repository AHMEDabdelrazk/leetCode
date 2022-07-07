# Write your MySQL query statement below
select name 'Customers' from Customers
left join Orders on Customers.id = Orders.customerId
where Orders.customerId is null