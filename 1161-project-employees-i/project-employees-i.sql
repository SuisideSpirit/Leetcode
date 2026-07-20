# Write your MySQL query statement below
SELECT project_id , ROUND(AVG(w2.experience_years),2) as average_years FROM 
Project as w1 LEFT JOIN Employee as w2 ON
w1.employee_id = w2.employee_id GROUP BY project_id ;