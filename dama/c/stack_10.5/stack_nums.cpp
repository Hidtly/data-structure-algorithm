#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100 
#define ERROR 0

/* 用数组实现堆栈 */

int i;

typedef int ElemType;
typedef struct SNode *Stack;  


struct SNode {
    ElemType Data[ MAXSIZE ];
    int Top;
};



/* 入栈 */
void Push( Stack Ptrs, ElemType item ) {
    if ( Ptrs->Top == MAXSIZE - 1 ) {
        printf( "堆栈满" );
        return ;
    } else {
        Ptrs->Data[ ++(Ptrs->Top) ] = item;
        return ;
    }
}

/* 出栈 */
ElemType Pop( Stack Ptrs ) {
    if ( Ptrs->Top == -1 ){
        printf( "堆栈空" );
        return ERROR;
    } else
        return ( Ptrs->Data[(Ptrs->Top)--] );    
}