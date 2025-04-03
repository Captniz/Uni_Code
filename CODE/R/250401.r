F <- function(x) {ifelse(x <= 0, 0, (1 + (x / 4.62)^5.62)^-2.5)}

# FALSE

FL <- function(x) {
  ifelse(x < 0, 
    (1/4)*exp(x/0.2)
    , 
    (1 - (1/4)*exp(-(x/0.2)))
  )
}

# probability of [-0.95, 1.39]
q3 <- FL(1.39) - FL(-0.95)
cat("q3 = ", q3, "\n")

q4 <- FL(0) - FL(0)
cat("q4 = ", q4, "\n")