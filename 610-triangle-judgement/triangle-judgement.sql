# Write your MySQL query statement below
SELECT x, y, z, IF(x + y >z AND z + y >x AND z + x >y , "Yes" , "No") AS Triangle  FROM 
TRIANGLE ;