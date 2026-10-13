Select v.customer_id, Count(customer_id) AS count_no_trans
FROM Visits v
LEFT JOIN Transactions t 
On v.visit_id=t.visit_id
where t.transaction_id is Null
Group by v.customer_id