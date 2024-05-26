#include<stdio.h>
#include<stdlib.h>

/* 用数组实现队列 */

#define MaxSize 100 
#define ERROR 0

typedef int ElemType;
typedef struct QNode *Queue;
struct QNode{
    ElemType Data[ MaxSize ];
    int rear;
    int front;
};

/* 入队 */
void AddQ ( Queue PtrQ, ElemType item ) {
    if ( (PtrQ->rear + 1) % MaxSize == PtrQ->front ) {
        printf( "队列满" );
        return ;
    }
    PtrQ->rear = ( PtrQ->rear + 1 ) % MaxSize;
    PtrQ->Data[ PtrQ->rear ] = item;
}
/* 出队 */
ElemType DeleteQ ( Queue PtrQ ) {
    if ( PtrQ->front == PtrQ->rear ) {
        printf( "队列空" );
        return ERROR;
    } else {
        PtrQ->front = ( PtrQ->front + 1 ) % MaxSize;
        return PtrQ->Data[ PtrQ->front ];
    }
}