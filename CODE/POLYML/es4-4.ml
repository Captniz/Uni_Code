fun flip ( [] ) = []
|   flip ( [(x,y)] ) = 
        if x<y
        then [(x,y)]
        else [(y,x)]
|   flip ( head :: tail ) = 
        flip ([head]) @ flip (tail)
;

flip([(3,1),(4,5),(9,1)]);