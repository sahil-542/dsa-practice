with t as (
    select c.user_id , count(*) as s
    from Confirmations c
    where c.action = "confirmed"
    group by user_id
)
select s.user_id,
    ifnull( round(s/count(c.action) , 2 ) , 0) as confirmation_rate
from Signups s
left join Confirmations c
on s.user_id = c.user_id
left join t 
on t.user_id = s.user_id
group by s.user_id
