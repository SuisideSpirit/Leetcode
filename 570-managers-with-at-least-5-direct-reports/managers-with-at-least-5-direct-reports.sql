# Write your MySQL query statement below
SELECT w1.name as name FROM 
Employee as w1 LEFT JOIN Employee as w2 ON 
w1.id = w2.managerId GROUP BY w1.id HAVING 
COUNT(*) >= 5 ;