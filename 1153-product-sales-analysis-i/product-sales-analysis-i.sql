# Write your MySQL query statement below
SELECT w2.product_name, w1.year ,w1.price FROM
Sales as w1 LEFT JOIN Product as w2 ON
w1.product_id = w2.product_id ; 