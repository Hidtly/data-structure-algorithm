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