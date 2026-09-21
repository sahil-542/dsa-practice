WITH FirstYearSales AS (
    SELECT 
        product_id, 
        year AS first_year, 
        quantity, 
        price,
        MIN(year) OVER (PARTITION BY product_id) AS min_year
    FROM Sales
)
SELECT 
    product_id, 
    first_year, 
    quantity, 
    price
FROM FirstYearSales
where first_year = min_year;
