fun duplicate( l : int list ) : int list = 
if tl(l)=nil 
then [hd(l)]@l
else [hd(l)]@[hd(l)]@duplicate(tl(l));



duplicate ([1,2,3,4,5]);