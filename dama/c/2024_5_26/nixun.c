#include <stdio.h>
#define condition 1
int main()
{
    int a[] = {1, 2, 3};
    int b[] = {0, 0, 0};

#if condition
    for (int i = 0; i < 3 / 2; i++)
    {
        int t = a[i];
        a[i] = a[3 - i - 1];
        a[3 - i - 1] = t;

    }/* 空间复杂度 S(n) = O(1)*/
#else
    for (int i = 0; i < 3; i++ ) 
        b[i] = a[3 - i - 1];
    for (int i = 0; i < 3; i++ )
        a[i] = b[i];
    /* 空间复杂度 S(n) = O(n)*/
#endif
    for (int i = 0; i < 3; i++)
    {
        printf("%d", a[i]);
    }
}
void niu(){}
