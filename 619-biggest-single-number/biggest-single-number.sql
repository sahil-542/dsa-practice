# Write your MySQL query statement below
With cte as
(select num 
from MyNumbers
group by num
having Count(*) = 1)

select max(num) as num from cte