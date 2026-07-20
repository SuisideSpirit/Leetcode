# Write your MySQL query statement below
SELECT w1.contest_id ,ROUND(
    (COUNT(w1.contest_id)/(SELECT COUNT(user_id) FROM Users))*100
    ,2) AS percentage FROM 
Register as w1 LEFT JOIN Users as w2 ON 
w1.user_id = w2.user_id GROUP BY 
w1.contest_id ORDER BY percentage DESC , w1.contest_id ;