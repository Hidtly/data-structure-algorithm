#include "stdio.h"
#include "stdlib.h"

void func(int (*)[5], int); // 声明
void func(int array[][5], int k){ // 定义
  //    int array (*p)[5]
  //    int *p
  //    int a[]
}

int func( int *array, int size ) {
    return array[0];
    // 等价于 *(array + 0)
}
//寻找值为 x 的数组下标 返回下标
int findX(int *array, int size, int x) {
    int flag = 0;
    int index = -1;
    for (int i = 0; i < size; i++){
        if ( array[i] == x ) {
            flag = 1;
            index = i;
        }

    }
    return index;
    /*
    if (flag)
        return index;
    else
        return -1;
    */
}
//获取数组下标为 k 的值 返回对应的值
int getX(int *array, int size, int k, int *px) {
    if ( k < 0 || k >= size )
        return 0;
    else {
        *px = array[k];
        return 1;
    }
}
int findMax(int *array, int size) {
    int max;
    max = array[0];
    for (int i = 1; i < size; i++) {
        if ( max < array[i])
            max = array[i];
    }
    return max;
}

int main()
{
    //int array[10] = {111, 22, 3333, 44, 55, 6, 7, 8, 9, 0};  //静态分配

    //int *p = malloc(100 * sizeof(int)); //动态分配


    /*
    printf("%d\n", *(array + 1));
    printf("%ld\n", sizeof(array));

    printf("%d\n", func(array, 100));

    func(array, 100);
    */

    /*
    int x;
    x = 22;
    int k;
    k = findX(array, 10, x);
    printf("%d\n", k);
    */

    /*
    int k = 33;
    int x, flag;
    flag = getX(array, 10, k, &x);
    printf("%d, %d\n", flag, x);
    */

    /*
    int max;
    max = findMax(array, 10);
    printf("%d\n", max);
    */

    int a[10] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9};
    int sum[11] = {0};
    int carry = 0; //进位
    for (int i = 0; i < 10; i++) {
        int s;
        s = a[i] + b[i] + carry;
        carry = s / 10;
        sum[i] = s % 10;
    }
    sum[10] = carry;
    for (int i = 10; i >= 0; i--) 
        printf("%d", sum[i]);
    putchar('\n');

    /*
    //一维定义
    int a[10];
    int *pa = a;

    // 二维定义
    int array[3][5]; //元素为 ：int [5]

    int(*p)[5];
    //int **p ×
    p = array;
    */

    return 0;
}