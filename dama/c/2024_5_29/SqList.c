#include <stdio.h>
#include <stdlib.h>

//#define ElemType int
#define LIST_INIT_SIZE 100
#define CONDITION 0

typedef int ElemType;

#if CONDITION
// 数组动态分配
typedef struct {
    ElemType *elem;
    int length;
} SqList;

#else
// 数组静态分配
typedef struct {
    ElemType elem[LIST_INIT_SIZE];
    int length;
} SqList;
SqList *L;

#endif
int main() 
{
   
}
