# Write your MySQL query statement below
SELECT name,bonus
From Employee e
left join Bonus b 
on e.empId = b.empId
where bonus is null or b.bonus < 1000