SELECT w.id
FROM Weather AS w
JOIN Weather AS w1
    ON w.recordDate = DATE_ADD(w1.recordDate, INTERVAL 1 DAY)
WHERE w.temperature > w1.temperature;