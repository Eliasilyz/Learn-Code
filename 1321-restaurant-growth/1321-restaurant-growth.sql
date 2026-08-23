# Write your MySQL query statement below
SELECT
    B.visited_on,
    SUM(A.amount) AS amount,
    ROUND(SUM(A.amount)/7,2) AS average_amount
FROM
    Customer AS A
JOIN
    (SELECT
        DISTINCT visited_on
     FROM
        Customer) AS B  
WHERE
    DATEDIFF(B.visited_on,A.visited_on) BETWEEN 0 AND 6
GROUP BY
    B.visited_on
HAVING
    COUNT(DISTINCT A.visited_on) = 7