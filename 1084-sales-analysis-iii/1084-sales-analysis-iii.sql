# Write your MySQL query statement below
SELECT
    P.product_id,
    P.product_name
FROM Product P
INNER JOIN Sales S ON P.product_id = S.product_id
GROUP BY P.product_id
HAVING MAX(QUARTER(S.sale_date)) = 1;