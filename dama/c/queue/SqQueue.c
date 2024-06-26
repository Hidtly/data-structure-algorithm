#include "stdio.h"
#include "stdlib.h"

#define MAX_Q_SIZE 100 // 最大队列长度

typedef int QElemType;
typedef int Status;

#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2
#define CONDITION   1

struct SqQueue{
    QElemType *base; // 初始化的动态分配内存空间
    int front;       // 头指针
    int rear;        // 尾指针
} ;

// 队列初始化
Status InitQueue(struct SqQueue *Q) {
    Q->base = (QElemType *)malloc(sizeof(QElemType) * MAX_Q_SIZE);
    if (!(Q->base))
        return OVERFLOW; // 储存分配失败
    Q->front = Q->rear = 0;
    return OK;
}

// 队列长度
int QueueLength(struct SqQueue Q) {
    return ((Q.rear - Q.front + MAX_Q_SIZE) % MAX_Q_SIZE);
}

// 队满
Status isFull(const struct SqQueue *Q) {
    return (Q->rear + 1) % MAX_Q_SIZE == Q->front;
}

// 队空
Status isEmpty(const struct SqQueue *Q) {
    return Q->front == Q->rear;
}

// 入队
Status EnQueue(struct SqQueue *Q, QElemType e) {
    if ( isFull(Q) ) // 队满了 返回错误
        return ERROR;
    else {
        Q->base[Q->rear] = e; // 新元素加入队尾
        Q->rear = (Q->rear + 1) % MAX_Q_SIZE; // 尾指针+1
        return OK;
    } 
}

// 出队
Status DeQueue(struct SqQueue *Q, QElemType *e) {
    if ( isEmpty(Q) ) // 队空 删除错误
        return ERROR;
    else {
        *e = Q->base[Q->front];
        Q->front = (Q->front + 1) % MAX_Q_SIZE;
        return OK;
    }
}

// 取队头
QElemType GetHead(const struct SqQueue *Q) {
    if(Q->front != Q->rear) // 队列不空
        return Q->base[Q->front];
}