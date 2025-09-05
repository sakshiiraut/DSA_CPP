# Write your MySQL query statement below
select p.product_id,
 round(ifnull(sum(p.price*u.units)/sum(u.units),0),2) as average_price 
 from Prices p left join UnitsSold u 
 on p.product_id = u.product_id 
and u.purchase_date  BETWEEN p.start_date AND p.end_date
 group by p.product_id