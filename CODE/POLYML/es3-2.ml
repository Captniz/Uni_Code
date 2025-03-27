fun cyclei( i : int, l : int list ) = 
    if i = 0 
    then 
        l 
    else 
        cyclei (
            i-1, 
            tl(l) @ [hd(l)]
        );


cyclei (2, [1,2,3,4,5]);