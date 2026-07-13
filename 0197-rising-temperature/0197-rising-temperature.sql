select w1.id #aliases because we are performing self join
from Weather w1
join Weather w2
on DATEDIFF(w1.recordDate,w2.recordDate)=1 #dates are 1 day apart
where w1.temperature>w2.temperature;