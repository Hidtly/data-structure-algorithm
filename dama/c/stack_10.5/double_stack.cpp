#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100 
#define ERROR 0

/* 一个数组两个堆栈 一个头 一个尾 */

int i;

typedef int ElemType;
typedef struct DStack *Stack; 

struct DStack {
    ElemType Data[ MAXSIZE ];
    int Top1;                                       /* 堆栈 1 的栈顶指针 */
    int Top2;                                       /* 堆栈 2 的栈顶指针 */
};

/*实现两个堆栈也就是实现两栈共享空间*/ 
Stack CreateStack( int MaxSize )
{
	Stack S=(Stack)malloc(sizeof(struct DStack));   //先为栈分配一个空间 
	//S->Data = (int*)malloc(sizeof(ElemType)*MaxSize);  //为栈分配一个maxsize大小的数组空间存放值 
	S->Top1 = -1;                                   //栈1为空时，栈顶指针指向-1 
	S->Top2 = MaxSize;                              //栈2为空时，栈顶指针指向MaxSize 
	//S->MaxSize = MaxSize;                         //栈的最大容量为MaxSize 
	return S;
}

/* 入栈 */
void Push( struct DStack *Ptrs, ElemType item, int Tag ) {
/* Tag 作为区分两个堆栈的标志，取值为 1 和 2  */
    if ( Ptrs->Top2 - Ptrs->Top1 == 1 ) {
        printf( "堆栈满" );
        return ;
    }
    if ( Tag == 1) {                                /* 对一个堆栈操作 */
        Ptrs->Data[ ++(Ptrs->Top1) ] = item;
    } else {                                        /* 对二个堆栈操作 */
        Ptrs->Data[ --(Ptrs->Top2) ] = item;
    }
    
}

/* 出栈 */
ElemType Pop( struct DStack *Ptrs, int Tag ) {
/* Tag 作为区分两个堆栈的标志，取值为 1 和 2  */
    if ( Tag == 1) {
        if ( Ptrs->Top1 = -1 ) {
            printf( "堆栈1为空" );
            return NULL;
        } else return Ptrs->Data[ (Ptrs->Top1)-- ];
    } else {
        if ( Ptrs->Top2 == MAXSIZE ) {
            printf( "堆栈2为空" );
            return NULL;
        } else return Ptrs->Data[ (Ptrs->Top2)++ ];
    }
}