#include <stdio.h>
#include "string.h"
// 传值
#if 0
void swap( float m, float n ) 
{
    float temp;
    temp = m;
    m = n;
    n = temp;
}
#else
// 传地址--用指针变量作为参数
void swap(float *m, float *n ) 
{
    float temp;
    temp = *m;
    *m = *n;
    *n = temp;
}
#endif
// 传地址--用数组名作为参数
void sub( char b[] )
{
    strcpy_s(b, 10, "world");
}
void main()
{
    //float a, b, *p1, *p2;
    /*
    scanf("%f,%f", &a, &b);
    swap(a, b);
    */

    /*
    scanf("%f,%f", &a, &b);
    p1 = &a;
    p2 = &b;
    swap(p1, p2);
    printf("a = %f, b = %f", a, b);
    */

    char a[10] = "hello";
    sub(a);
    printf("%s", a);
}
