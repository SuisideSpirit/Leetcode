# Write your MySQL query statement below
SELECT w2.id as ID from Weather as w1 JOIN 
Weather as w2 ON DATEDIFF(w2.recordDate , w1.recordDate ) = 1
AND w1.temperature < w2.temperature ;