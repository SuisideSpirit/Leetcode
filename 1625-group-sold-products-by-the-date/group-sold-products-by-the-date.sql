# Write your MySQL query statement below
SELECT w1.sell_date , COUNT(DISTINCT(w1.product)) as num_sold , 
GROUP_CONCAT(DISTINCT product ORDER BY product SEPARATOR ',') AS products
FROM Activities as w1 GROUP BY sell_date ; 