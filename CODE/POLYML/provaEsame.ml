datatype tree = Leaf of int | Node of int * tree * tree | Empty;
val example_tree = Node(1, Node(1, Leaf(3), Node(2, Leaf 1, Leaf 2)), Leaf 2);

fun find_in_tree (Empty, _):int = 
        0
|   find_in_tree ((Node(y,left,right)),x:int):int =
        if y = x
        then
           1+find_in_tree(left,x) + find_in_tree(right,x)
        else
            find_in_tree(left,x) + find_in_tree(right,x)
| find_in_tree (Leaf(y), x:int):int =
        if y = x
        then 
            1
        else 
            0
; 

fun count_tree_list(_, []:int list):int = 
    0
|   count_tree_list(Empty,_):int = 
    0
|   count_tree_list((Leaf(y)), h::t):int = 
    if t=nil
    then
        find_in_tree((Leaf(y)), h)
    else
        find_in_tree((Leaf(y)), h)+count_tree_list((Leaf(y)), t)
|   count_tree_list((Node(y,left,right)), h::t):int = 
    if t=nil
    then
        find_in_tree((Node(y,left,right)), h)
    else
        find_in_tree((Node(y,left,right)), h)+count_tree_list((Node(y,left,right)), t)
;

count_tree_list(example_tree, [5,4]);