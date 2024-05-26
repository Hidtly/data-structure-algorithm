#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100 
#define ERROR 0

/* 用链表实现堆栈 */

/* top一定是在链表的头上 不能在尾部 */

typedef int ElemType;
typedef struct SNode *Stack;  
struct SNode {
    ElemType Data;
    struct SNode *Next;
};

/*
1、 堆栈初始化
2、 判断堆栈 S 是否为空 
 */

Stack CreateStack () 
{ /* 构建一个堆栈头结点，返回指针 */
    Stack S;
    S = ( Stack ) malloc ( sizeof(struct SNode) );
    S->Next = NULL;
    return S;  
}
int IsEmpty ( Stack S ) 
{ /* 判断堆栈S是否为空， 为空返回整数1，否则返回0 */
    return ( S->Next == NULL );
}
void Push ( ElemType item, Stack S )
{ /* 将元素item压入堆栈S */
    struct SNode *TmpCell;
    TmpCell = ( struct SNode* )malloc( sizeof(struct SNode) );
    TmpCell->Data = item;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
}
ElemType Pop ( Stack S )
{ /* 删除并返回堆栈S的栈顶元素 */
    struct SNode *FirstCell;
    ElemType TopElem;
    if ( IsEmpty( S ) ) {
        printf( "堆栈空" );
        return NULL;
    } else {
        FirstCell = S->Next;
        S->Next = FirstCell->Next;
        TopElem = FirstCell->Data;
        free( FirstCell );
        return TopElem;
    }
} 