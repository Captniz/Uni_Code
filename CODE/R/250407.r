F <- function(x) {
    #create an array
    # [0.1 , 0.05 , 0.04 , 0.04 , 0.19 , 0.16 , 0.18 , 0.24]
    
    if (x == 1) {
        return(0.1)
    } else if (x == 2) {
        return(0.05)
    } else if (x == 3) {
        return(0.04)
    } else if (x == 4) {
        return(0.04)
    } else if (x == 5) {
        return(0.19)
    } else if (x == 6) {
        return(0.16)
    } else if (x == 7) {
        return(0.18)
    } else if (x == 8) {
        return(0.24)
    } else {
        stop("Invalid input")
    }
}

#Q1

#pass a vector from 1 to 12
q1 <- F(1)

cat("q1 = ", q1, "\n")
