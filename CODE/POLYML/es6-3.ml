(* Write a function tabulate that takes an initial value 𝑎, an
increment , a number of points 𝑛, and a function 𝐹 from reals to
reals and print a table with columns corresponding to 𝑥 and 𝐹(𝑥),
where 𝑥 = 𝑎, 𝑎 + 𝛿 , 𝑎 + 2𝛿, . . . , 𝑎 + (𝑛 − 1)𝛿 *)

fun tabulate(a : real, i : real, 0, F : (real -> real)) = ()
|   tabulate(a : real, i : real, p : int, F : (real -> real)) =
(
    print(Real.toString(a)^"\t");
    print(Real.toString(F(a))^"\n");
    tabulate(a+i,i,p-1,F)
);



tabulate(1.0,0.1,9,fn x => x*x);
