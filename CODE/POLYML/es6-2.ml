(* Write a factorial function fact that, given an integer n,
returns n!, 1 when its argument is 0, 0 for a negative
argument with an error message “Negative argument x
found” where x is the negative argument *)

exception negativeNum of int;

fun fact(n : int) : int =
let
    fun innerFact(0) = 1
    | innerFact(x) = 
    if x>0 
    then 
        x * innerFact(x-1)
    else
        raise negativeNum x
in
    innerFact(n) handle negativeNum x =>(
        print ("Negative argument " ^ Int.toString x ^ " found\n");
        0
    )
end;

fact ~5 ;
