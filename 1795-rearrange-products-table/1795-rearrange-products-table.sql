# Write your MySQL query statement below
select * from (
    select product_id, 'store1' as store, store1 as price from products 
    union
    select product_id, 'store2' as store, store2 as price from products 
    union
    select product_id, 'store3' as store, store3 as price from products 
    order by 1) as U
where U.price is not null
;