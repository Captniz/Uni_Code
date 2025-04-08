F <- function(x) {
  ifelse(x < -2, 
    0,
    ifelse(-2 <= x && x < 1, 
      0.18
      ,
      ifelse(1 <= x && x < 3,
        (0.059*x^2) + (-0.106*x) + 0.407
        ,
        ifelse(3 < x && x < 5,
          (0.13*x)+0.35
          ,
          ifelse(x >= 5,
            1,
            NA
          )
        )    
      )
    )
  )
}

#Q1
q1 <- 0.62 - F(2)

cat("q1 = ", q1, "\n")
#Q2

