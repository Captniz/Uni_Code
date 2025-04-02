fun maxList ( [] ) = []
|   maxList ( [last] ) = [ last ]
|   maxList ( head :: second :: tail ) = 
    if head > second
    then maxList ( [head] @ tail )
    else maxList ( [second] @ tail ); 

maxList([2,10,3]);