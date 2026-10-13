Select a.id 
FROM weather a
INNER JOIN weather b
ON Datediff(a.recordDate,b.recordDate)=1
where a.temperature>b.temperature;
