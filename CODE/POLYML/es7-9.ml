(*Write a function sumTree for a mapTree T of type (‘a,’b)
mapTree. The function visits the tree and returns the sum
of the second component of the label of all nodes*)

datatype 'a btree =
Empty |
Node of 'a * 'a btree * 'a btree;

type ('x , 'y) mapTree = ('x * 'y) btree;

fun sumTree (Empty) = 0
| sumTree (Node((x,y),lt,rt)) = 
    y+sumTree(lt)+sumTree(rt)
;

sumTree (Node(("a",1), Node(("c",2), Empty, Node(("d",3), Empty, Empty)), Empty));