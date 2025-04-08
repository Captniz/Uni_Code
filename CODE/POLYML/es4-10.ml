(*
fun powerSet ( [] ) = [[]]
|   powerSet ( [last] ) = [ [last], [] ]
|   powerSet ( head ::  tail ) = 
    [ [head]@tail ] @ powerSet(tail) 
;
*)

fun powerSet ( [] ) = [[]]
|   powerSet ( [last] ) = [ [] ]
|   powerSet ( head ::  tail ) =
    if tail = [] then
        [ [head] ]
    else
        powerSet(tail) 
;




(* Inizia dalla fine, scorri fino alla fine a aumenta*)

powerSet([1,2,3,4,5]);