(*Given a function 𝐹 that takes a parameter of
product type with 𝑛 components and the
𝑛 components, define a function curry that
applied to 𝐹 produces a function G such that*)


fun curry F x y z = F(x,y,z);


curry (fn (x,y,z)=>x*y*z) 1 2 3;