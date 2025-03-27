fun fact( n : int ) : int = 
    n * (
        if n = 1 
        then 1 
        else fact (n-1)
    );


fact (1);
fact (3);
fact (10);