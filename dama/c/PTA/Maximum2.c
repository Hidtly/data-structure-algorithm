#include "stdlib.h"
#include "stdio.h"
#include <math.h>
#include <time.h>


#define N 100010

int MaxSubseqSum(int A[], int n)
{
    int ThisSum = 0, MaxSum = -1;
    int l = 0;
    int r = n - 1;
    int i, t;
    for (i = 0; i < n; i++)
    {
        ThisSum += A[i];
        if (MaxSum < ThisSum)
        {
            MaxSum = ThisSum;
            l = t;
            r = i;
        }
        else if (ThisSum < 0)
        {
            ThisSum = 0;
            t = i + 1;
        }
    }
    if (MaxSum < 0)
        printf("0 %d %d", A[0], A[n - 1]);
    else
        printf("%d %d %d", MaxSum, A[l], A[r]);
    return 0;
}
int main()
{
    int i, x;
    int a[N] = {0};
    scanf("%d", &x);
    for (i = 0; i < x; i++)
        scanf("%d", &a[i]);
    MaxSubseqSum(a, x);
    return 0;
}