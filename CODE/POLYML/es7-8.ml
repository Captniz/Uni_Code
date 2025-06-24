(*Define a type mapTree that is a specialization of btree so
that it has a label type that is a set of domain-range pairs
• Define a tree t1 that has a single node with the pair ("a",1)
at the root*)

datatype 'a btree =
Empty |
Node of 'a * 'a btree * 'a btree;

type ('x , 'y) mapTree = ('x * 'y) btree;


val t1 : ( string, int ) mapTree = Node(("a",1), Empty, Empty) : ( string, int ) mapTree ;
