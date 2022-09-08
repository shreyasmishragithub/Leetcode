# Write your MySQL query statement below
select Person.firstName,Person.lastName,Address.state,Address.city from Person left join Address on Person.personId=Address.personId