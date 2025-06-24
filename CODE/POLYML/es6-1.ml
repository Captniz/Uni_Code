(* Write a program returnThird(L) that, given a list of
integers L, returns its third element. If the list is too short, it
raises an exception shortList and handles it by printing
“List too short.\n It only contains n elements.\n” where n is
the number of elements in the list. *)

exception shortList of int;

fun returnThird(L : 'a list) : 'a =
let
    fun innerThird(nil) = raise shortList 0
    | innerThird([x]) = raise shortList 1
    | innerThird([x,y]) = raise shortList 2
    | innerThird(_::_::x::_) = x;
in
    innerThird(L) handle shortList n =>(
        print ("List too short.\nIt only contains " ^ Int.toString n ^ " elements.\n");
        raise shortList n
    )
end;

returnThird [1, 2,3];

length [1, 2, 3, 4, 5]; (* This will return the third element, which is 3 *)