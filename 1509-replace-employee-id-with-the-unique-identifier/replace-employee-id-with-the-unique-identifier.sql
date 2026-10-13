select EmployeeUNI.unique_id ,Employees.name
from Employees
LEFT JOIN EmployeeUNI 
On Employees.id=EmployeeUNI.id

