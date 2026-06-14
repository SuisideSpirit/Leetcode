# Write your MySQL query statement below
SELECT w1.firstName , w1.lastName ,w2.city ,w2.state from Person as w1 LEFT JOIN Address as w2 on 
w1.personId = w2.personId ;
