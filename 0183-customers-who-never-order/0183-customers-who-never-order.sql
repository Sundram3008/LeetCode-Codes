# Write your MySQL query statement below
select name as Customers from Customers c where not exists (select customerId from Orders o where c.id = o.customerId); 