n <- 28
p <- 0.169

vatteso <- 0
for (x in 0:n) {
  vatteso <- vatteso + dbinom(x, n, p)*x;
} 

cat("La media attesa è ", vatteso, "\n")

n <- 141