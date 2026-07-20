# Write your MySQL query statement below
SELECT w2.product_id ,IFNULL(ROUND(SUM(w1.units * w2.price) / SUM(w1.units),2),0) AS average_price FROM 
Prices as w2 LEFT JOIN UnitsSold as w1
ON w1.product_id = w2.product_id AND (w1.purchase_date BETWEEN w2.start_date AND w2.end_date) 
GROUP BY product_id ;