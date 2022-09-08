# Write your MySQL query statement below
select p.product_id from Products as p inner join Products as q on p.product_id=q.product_id where p.low_fats=q.recyclable and p.low_fats='Y';