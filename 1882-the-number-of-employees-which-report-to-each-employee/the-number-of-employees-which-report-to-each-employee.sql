# Write your MySQL query statement below
SELECT w1.employee_id , w1.name , COUNT(w2.reports_to) AS reports_count ,
ROUND(AVG(w2.age)) AS average_age 
FROM Employees as w1 JOIN Employees as w2 ON
w1.employee_id = w2.reports_to  GROUP BY w1.employee_id ORDER BY w1.employee_id;