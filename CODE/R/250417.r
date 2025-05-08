# n <- 0:25
# tiri <- 100
# N <- dbinom(n, 25, 1/7)


# cat("X:", X, "\n")
# cat("N:", N, "\n")

# ValAttX <- function(x) {
#     E <- 0
#     for (i in 1:length(x)) {
#         E <- E + x[i] * X[i]
#     }
#     return(E)
# }
# ValAttN <- function(x) {
#     E <- 0
#     for (i in 1:length(x)) {
#         E <- E + x[i] * N[i]
#     }
#     return(E)
# }

# PXIY <- function(x) {

# }


# PXeY <- function(x) {Px() * PXY(x)}





# Var <- function(x) {
#     E <- E(x)
#     E2 <- E(x^2)
#     return(E2 - E^2)
# }

n <- 0:10
N <- dgeom(n, 1/7)

for (i in 1:length(n)) {
    cat("Successo al:\t",i, "\ttentativo: " , N[i], "\n")
}

cat ("\n\n")


x <- 0:4
len <- 4
X <- dbinom(x, len, 1/6)

for (i in 1:length(x)) {
    cat("Prob di ottenere:\t",i-1, "\tnumeri 5: " , X[i], "\n")
}

#============================================================

PXIN <- function(y) {
    X <- 0:(y-1)
    px <- dbinom(X, y-1, 1/6)
    return(px)
}

ValAttPXIN <- function(y) {
    E <- 0
    X <- 0:(y-1)
    for (x in X) {
        E <- E + x * PXIN(y)[x]
    }
    return(E)
}

ValAttPXpow2IN <- function(y) {
    E <- 0
    X <- 0:(y-1)
    for (x in X) {
        E <- E + x * PXIN(y)[x]
    }
    return(E)
}

VarPXIN <- function(y, p) {
    # np(1-p) Varianza di una binomiale
    (y-1)*p*(1-p)
}


cat("\n======================\n")
#============================================================

# Q1
q1 <- VarPXIN(5,1/6)
cat("q1: ", q1, "\n")

# Q2
#????


# Q3
z<-function(x) {n_values <- 6 * x + 1 ifelse(n_values == floor(n_values) & n_values >= 1, (1/7) * (6/7)^(n_values - 1), 0)}
cat("Q3: ", z(0), "\n")