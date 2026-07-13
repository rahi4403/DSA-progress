select Product.product_name,Sales.year,Sales.price
FROM sales
left join Product
on Sales.product_id=Product.product_id