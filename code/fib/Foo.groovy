def fib(i) {
    switch ( i ) {
        case [0, 1]:
            return i
        default:
                return fib(i-1) + fib(i-2)
    }
}

def gib(i) {
    if (i < 2) 
        return i
    else
        return gib(i-1) + gib(i-2)
}

println(gib(40));
