(*Parte 3 -- verifica dei quadrati*)

val sudoku = [
    [5, 3, 0, 0, 7, 0, 0, 0, 0],

    [6, 0, 0, 1, 9, 5, 0, 0, 0],

    [0, 9, 8, 0, 0, 0, 0, 6, 0],

    [8, 0, 0, 0, 6, 0, 0, 0, 3],

    [4, 0, 0, 8, 0, 3, 0, 0, 1],

    [7, 0, 4, 0, 2, 0, 0, 0, 6],

    [0, 6, 0, 0, 0, 0, 2, 8, 0],

    [0, 0, 0, 4, 1, 9, 0, 0, 5],

    [0, 0, 0, 0, 8, 0, 0, 7, 9]
];

(*Finds the occurrencies of a given value in a list of 3
    L : list
    num : value to find
    ctr : 0
    found : 0
*)
fun find3 (L : int list, num : int, ctr : int, found : int) : int =
if ctr=3
then
    found
else 
    if hd(L) = num
    then
        find3(tl(L), num, ctr+1, found+1)
    else
        find3(tl(L), num, ctr+1, found);


(*Given a list shortens it to a list of 3 elements, starting from the start
    L : list
    start : start offset
    ctr : 0
*)
fun get3Line(L : int list , start : int , ctr : int) : int list = 
if ctr=start
then
[hd(L),hd(tl(L)),hd(tl(tl(L)))]
else
get3Line(tl(L),start,ctr+1);



(*Given a matrix gets a square matrix 3x3 starting from the offsetx and y
    L : matrix
    offsetx : x axis offset
    offsety : y axis offset
    ctry : 0
*)
fun getSquare( L : int list list, offsetx : int, offsety : int, ctry : int) : int list list =
if ctry = offsety
then
[get3Line(hd(L),offsetx,0),get3Line(hd(tl(L)),offsetx,0),get3Line(hd(tl(tl(L))),offsetx,0)]
else
getSquare(tl(L), offsetx, offsety, ctry+1);


(*Given a square matrix 3x3 verifies there are no double values, every value is represented 1 time or substituted by a 0
    L : matrix
    ctr : 1
    sum : 0
*)
fun verifySquare(L : int list list, ctr : int, sum : int) : bool =
if ctr = 10
then
    if sum = 9
    then
        true (*Valido*) 
    else
        if find3(hd(L),0,0,0)+find3(hd(tl(L)),0,0,0)+find3(hd(tl(tl(L))),0,0,0) = 9 - sum
        then
            true
        else
            false (*Non è valido*)
        
else
    if find3(hd(L),ctr,0,0)+find3(hd(tl(L)),ctr,0,0)+find3(hd(tl(tl(L))),ctr,0,0) > 1
    then
        false
    else
        verifySquare(L,ctr+1,sum+find3(hd(L),ctr,0,0)+find3(hd(tl(L)),ctr,0,0)+find3(hd(tl(tl(L))),ctr,0,0));


(*Given a square matrix 9x9 verifies there are no double values, every value is represented 1 time or substituted by a 0
    L : matrix
    ctr : 1
    sum : 0
*)
fun verifySudokuSquares(L : int list list, ctrx : int,ctry : int, truth: bool) : bool =
if truth = false
then
    false
else 
    if ctrx = 6
    then
        if ctry = 6
            then    
                true andalso verifySquare(getSquare(L,ctrx,ctry,0),1,0)
            else
                verifySudokuSquares(L, 0 , ctry+3 , truth andalso verifySquare(getSquare(L,ctrx,ctry,0),1,0))
    else
        verifySudokuSquares(L, ctrx+3 , ctry , truth andalso verifySquare(getSquare(L,ctrx,ctry,0),1,0));


verifySudokuSquares(sudoku,0,0,true);