fun power ( _ :real , 0 :int ) = 1.0
|   power ( base:real, exp:int ) = base * power(base,exp-1);

power(2.1,3);