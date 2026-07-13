select Employee.name,Bonus.bonus
from employee
left join Bonus
on Employee.empId=Bonus.empId
where Bonus.bonus<1000 or Bonus.bonus IS null
