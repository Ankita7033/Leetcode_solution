# Write your MySQL query statement below
SELECT actor_id , director_id
From ActorDirector
Group by actor_id ,director_id
having count(timestamp) >= 3;