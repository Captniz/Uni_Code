#Q1
FL <- function(x) {
  ifelse(x <= 0, 
    0,
    ifelse(x >= 6, 
        1
        ,
        (1/36)*x^2
    )
  )
}

#Q2
q2 <- FL(4.99) - FL(0.4)
cat("q2 = ", q2, "\n")

p <- FL(2.72)
cat("FL(2.72) = ", p, "\n")

#0.5455111 = 1/36*x^2
#sqrt(0.5455111/(1/26)) =x

F <- function() {
    sqrt(0.5455111/(1/36))
}

cat("F = ", F(), "\n")
cat("proof = ", FL(F())-FL(2.72), "\n")
