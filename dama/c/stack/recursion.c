#include "stdio.h"
#include "stdlib.h"
// This is a series of recursion program

// n!
long Fact( long n ) {
    if ( n == 0 )
        return 1;
    else
        return n * Fact(n - 1);
}

// Fibonaci
long Fib( long n ) {
    if ( n == 1 || n == 2 )
        return 1;
    else
        return Fib(n - 1) + Fib(n - 2);
}