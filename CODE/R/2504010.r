A=0.24+0.04+0.07;
Ac=1-A;

q1=pbinom(8,16,A)

cat ("q1 = ", q1, "\n") 

q2=dgeom(2,A)

cat ("q2 = ", q2, "\n")

q3=pgeom(2,A)

cat ("q3 = ", q3, "\n")