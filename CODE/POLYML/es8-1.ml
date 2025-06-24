
signature SET =
sig
    type 'a set
    val emptyset: 'a set
    val isin: (''a set * ''a) -> bool
    val addin: (''a set * ''a) -> ''a set
    val removefrom: (''a set * ''a) -> ''a set
end;

structure Set = 
struct
    type 'a set = 'a list;
    val emptyset = [];

    fun isin( nil , _ ) = false
    | isin( h::tl , x) = if h=x then true else isin(tl,x);
    
    fun addin ( [] , x ) = [x]
    | addin(L , x) = if isin(L,x) then L else x::L;

    fun removefrom ( [] , _ ) = []
    | removefrom(h::tl , x) = if h=x then tl else h::removefrom(tl,x);

end :> SET;

val a = Set.emptyset;
val b = Set.addin(a,1);