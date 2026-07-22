# Write your MySQL query statement below
SELECT w2.product_name , SUM(w1.unit) AS unit FROM 
Orders as w1 LEFT JOIN Products as w2 ON 
w1.product_id = w2.product_id WHERE w1.order_date >= "2020-02-01"
AND w1.order_date <= "2020-02-29" GROUP BY w1.product_id HAVING SUM(w1.unit) >=100 ;