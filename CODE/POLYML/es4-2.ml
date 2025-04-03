fun del ( [], _ ) = []
|   del ( head::tail , i ) =
    if i = 0 
    then tail
    else [head]@del(tail, i-1)
;

del([1,2,3,4,5,6,7],10);