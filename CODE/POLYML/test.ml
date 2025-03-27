fun third ( l: int list ) : int = hd  (tl (tl l));

third [1,2,3,4];

fun rev ( x,y,z ) = (z,y,x); 

rev (1,2,3);

fun fact( n : int ) : int = 
    n * (if n = 1 
        then 
            1 
        else 
            fact (n-1)
    );


fact (1);

