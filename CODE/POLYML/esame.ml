datatype Tree =
Empty |
Leaf of int|
Node of int * Tree * Tree;


fun maxtree(Empty) : (int list * int) = ([],0)
| maxtree(Leaf(x)) : (int list * int) = ([x],x)
| maxtree(Node(x,lt,rt)) : (int list * int) =
let
    val ltf = maxtree(lt);
    val rtf = maxtree(rt);
in
    if #2 rtf > #2 ltf
    then
        (x::(#1 rtf) ,#2 rtf+x)
    else
        (x::(#1 ltf),#2 ltf +x)
end
;

maxtree(
    Node(1,
        Node(10,
            Empty,
            Empty
        ),
        Node(3,
            Node(10,
                Empty,
                Empty
            ),
            Empty
        )
    )
);
