#include "stdlib.h"
#include "stdio.h"

// 链表实现队列

typedef struct {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front; // 队列头指针
    Node *rear; // 队列尾指针
} Queue;


// 初始化
void init( Queue *q ) {
    if (!(q->front = q->rear = (Node *)malloc(sizeof(Node))))
        return errno;
    q->front = q->rear = NULL;
}

// 判断队空
int isEmpty(const Queue *q) {
    return q->front == NULL;
}

// 入队 不考虑内存不够会失败
void enQueue(Queue *q, int x) {
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
}


int main(void)
{
    printf("%d", 5);
    return 0;
}