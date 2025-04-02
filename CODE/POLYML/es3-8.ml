fun shift ([]:int list):int list = []
|   shift (x :: xs) = xs @ [x];

shift [];