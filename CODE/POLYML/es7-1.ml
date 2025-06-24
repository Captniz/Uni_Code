(*Write, in curried form, a function applyList that
takes a list of functions and a value and applies
each function to the value, producing a list of the
results. If the list is empty it returns the empty list.*)

fun applyList nil _ = []
| applyList (h::tl) n =
    h(n)::applyList tl n
;

applyList [fn x=>x*2, fn x => x*x*x] 4