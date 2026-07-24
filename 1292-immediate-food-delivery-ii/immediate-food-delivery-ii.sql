# Write your MySQL query statement below
SELECT ROUND(
    (SUM(order_date = customer_pref_delivery_date)/COUNT(*)) * 100 ,2) 
    as immediate_percentage FROM 
Delivery as w1 WHERE 
order_date =
(SELECT MIN(order_date) FROM Delivery as w2 WHERE w1.customer_id = w2.customer_id) ;