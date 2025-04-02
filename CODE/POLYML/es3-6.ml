fun maxList( l : string list ) : string list = 
if tl(l)=nil 
then l
else
    if hd(l) > hd(tl(l)) 
    then maxList([hd(l)]@tl(tl(l)))
    else maxList(tl(l));



maxList ([ "a","abc","aab" ]);

(* 1 2 3 4 5 *)