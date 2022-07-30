select d.name as Department, y.name as Employee, Salary
from(
Select id, name, salary, departmentID, 
dense_rank() over(partition by departmentId order by salary desc ) as rnk
from employee
    ) y 
join Department d
on d.id=y.departmentID
where rnk<=3