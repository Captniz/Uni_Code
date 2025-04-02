fun pow( base:real , exp:int ) : real = 
if exp=0 
then 1.0
else base*pow(base,exp-1);



pow ( 2.1 , 3 );