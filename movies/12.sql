SELECT movies.title
FROM movies
JOIN stars AS sc ON movies.id = sc.movie_id
JOIN people AS p1 ON sc.person_id = p1.id
JOIN stars AS sj ON movies.id = sj.movie_id
JOIN people AS p2 ON sj.person_id = p2.id
WHERE p1.name = 'Bradley Cooper' AND p2.name = 'Jennifer Lawrence';
