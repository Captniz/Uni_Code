fun powerSet ( [] ) = [[]]
|   powerSet ( [last] ) = [ [] , [last] ]
|   powerSet ( head :: second :: tail ) = 
    [ [head]@[second]@tail ] @ powerSet([second]@tail) @ powerSet([head,second])  
;

powerSet([1,2,3]);