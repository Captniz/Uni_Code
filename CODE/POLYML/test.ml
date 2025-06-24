signature MESSAGE = sig type message val createMessage : string -> message end;

structure StringMsgH :> MESSAGE = struct type message = string; fun createMessage s = s; fun printMessage s = print(s); end;

StringMsgH.createMessage "Hello world";
StringMsgH.printMessage "Hello world";