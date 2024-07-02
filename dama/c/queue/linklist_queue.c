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
void init( Queue *Q ) {
    if (!(Q->front = Q->rear = (Node *)malloc(sizeof(Node))))
        return errno;
    Q->front = Q->rear = NULL;
}

// 判断队空
int isEmpty(const Queue *Q) {
    return Q->front == NULL;
}

// 入队 不考虑内存不够会失败
void enQueue(Queue *Q, int x) {
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
}

// 销毁队列
int DestroyQueue(Queue *Q)
{
#if 0
    // 通过新建一个变量来销毁
    Queue *p = (Queue *)malloc(sizeof(Queue));
    while (Q->front) {
        p = Q->front->next;
        free(p);
        Q->front = p;
    }
#else
    // 通过尾指针销毁
    while (Q->front) {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
#endif
    return 1;
}

// 入队
int EnQueue(Queue *Q, int e) {
    Node * p = (Node *)malloc(sizeof(Node));
    if(!p)
        return -1;// 内存分配失败
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return 1;
}

// 出队
int PopQueue(Queue *Q, int *e) {
    if (isEmpty(Q))
        return -1;
    Node *p = (Node *)malloc(sizeof(Node));
    if (!p)
        return -1; // 内存分配失败
    p = Q->front->next;
    e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p) { //如果头结点的下一结点为尾节点 要把尾指针指向头结点
        Q->rear = Q->front;
    }
    free(p);
    return 1;
}

// 取队头元素
int GetHead(Queue *Q, int *e) {
    if (isEmpty(Q))
        return -1;
    e = Q->front->data;
    return 1;
}
int main(void)
{
    printf("%d", 5);
    return 0;
}