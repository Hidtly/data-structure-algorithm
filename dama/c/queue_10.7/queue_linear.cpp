#include<stdio.h>
#include<stdlib.h>

/* 用单向链表实现队列 */

#define MaxSize 100 
#define ERROR 0

typedef int ElemType;
typedef struct QNode *Queue;

struct Node {
    ElemType Data;
    struct Node *Next;
};
struct QNode { /* 链队列结构 */
    struct Node *front; /* 指向队头的结点 */
    struct Node *rear;  /* 指向队尾的结点 */
    };
Queue PtrQ;

/* 出队 */ 
ElemType DeleteQ ( Queue PtrQ ) {
    struct Node *FrontCell;
    ElemType FrontElem;

    if ( PtrQ->front == NULL ) {
        printf( "队列为空" );
        return ERROR;
    }
    FrontCell = PtrQ->front;
    if ( PtrQ->front == PtrQ->rear )  /* 若队列只有一个元素 */
        PtrQ->front = PtrQ->rear = NULL;/* 删除后队列置为空 */
    else
        PtrQ->front = PtrQ->rear->Next;
    FrontElem = FrontCell->Data;
    free( FrontCell );/* 释放被删除结点空间 */
    return FrontElem;
}