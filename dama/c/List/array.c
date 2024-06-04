#include "stdio.h"
#include "stdlib.h"

int func( int *array, int size ) {
    return array[0];
    // 等价于 *(array + 0)
}
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

int getX(int *array, int size, int k) {
    
}

    int main()
{
    int array[10] = {111, 22, 3333, 44, 55};  //静态分配

    int *p = malloc(100 * sizeof(int)); //动态分配


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

    int k = 3;
    int x;
    x = getX(array, 10, k);
    return 0;
}