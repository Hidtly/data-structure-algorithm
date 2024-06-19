#include "stdlib.h"
#include "stdio.h"
#include<math.h>
#include<time.h>

#define N 100010

int MaxSubseqSum(int A[],int n)
{
  int ThisSum=0,MaxSum=0;
   int i;
    for(i=0;i<n;i++)
    {
        ThisSum+=A[i];
        if(MaxSum<ThisSum)
            MaxSum=ThisSum;
        else if(ThisSum<0)//等于负数时,前面的数肯定不是最大子列和了,再从当前进行求最大值.
            ThisSum=0;
    }
    return MaxSum;
}
int main()
{
       int i,x;
       int a[N]={0};
       scanf("%d",&x);
       for(i=0;i<x;i++)
       scanf("%d",&a[i]);
       printf("%d",MaxSubseqSum(a,x));
       return 0;
}
