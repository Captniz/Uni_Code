fun shiftn ( [], _ ) = []
|   shiftn ( x :: xs , 0 : int ) = [x] @ xs
|   shiftn ( x :: xs , n : int ) = shiftn( xs @ [x] , n-1);

shiftn([1,2,3,4],2);