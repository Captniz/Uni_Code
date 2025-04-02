fun duplicate ( [] ) = []
|   duplicate ( x :: xs ) = [x] @ [x] @ duplicate(xs);

duplicate([1,2,3,4]);