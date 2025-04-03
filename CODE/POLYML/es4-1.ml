fun flip ( [] ) = []
|   flip ( [last] ) = [ last ]
|   flip ( head :: second :: tail ) = 
    [second]@[head]@flip (tail)
;

flip([1,2,3,4,5,6,7]);