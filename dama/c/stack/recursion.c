#include "stdio.h"
#include "stdlib.h"
// This is a series of recursion program

/**
 * 分治法解决递归问题算法的一般形式：
 * void p ( 参数表 ) {
 *      if ( 递归结束条件 ) 可直接求步骤； ----基本项
 *      else p ( 较小的参数 );           ----归纳项
 * }
 *
 */

// n!
long Fact( long n ) {
#if 1
    // 递归
    if ( n == 0 )
        return 1;
    else
        return n * Fact(n - 1);
#else  // for循环
    int t = 1;
    for (int i = 1; i <= n; i++)
        t = t * i;
    return t;
#endif
}

// Fibonacci
long Fib( long n ) {
    if ( n == 1 || n == 2 )
        return 1;
    else
        return Fib(n - 1) + Fib(n - 2);
}