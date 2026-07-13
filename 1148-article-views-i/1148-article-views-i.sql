SELECT DISTINCT author_id as id #using alias to rename the column 
FROM Views 
WHERE author_id=viewer_id

ORDER BY author_id ASC #arranging in ascending order