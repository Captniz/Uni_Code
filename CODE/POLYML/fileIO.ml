val inStream = TextIO.openIn "input.txt"
val line = TextIO.inputLine inStream
val _ = TextIO.closeIn inStream

val outStream = TextIO.openOut "output.txt"
val _ = TextIO.output (outStream, "Hello, world!\n")
val _ = TextIO.closeOut outStream

fun readAllLines stream =
  case TextIO.inputLine stream of
      "" => []
    | line => line :: readAllLines stream

val inStream = TextIO.openIn "input.txt"
val lines = readAllLines inStream
val _ = TextIO.closeIn inStream