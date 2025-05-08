F <- function(x) {1/(1 + exp(-0.4*x))}

FL <- function(x) {
    ifelse(x < 0, 
        1/2*exp(x/0.4)
        , 
        1-1/2*exp(-x/0.4)
    )
}
#Q3
q3 <- FL(1.13) - FL(0.94)
cat("q3 = ", q3, "\n")

#Q4
q4 <- FL(0)
cat("q4 = ", q4, "\n")