#include "stdio.h"
#include "stdlib.h"

// 数组实现队列

struct Queue {
    int *data;
    int capacity;
    int front;
    int rear;
};

// 初始化函数
void init(struct Queue *pq, int capacity) {
    pq->capacity = capacity;
    pq->data = (int *)malloc(sizeof(int) * (capacity + 1)); // front与rear差1
    pq->front = pq->rear = 0;
}
// 判断是否为满
int isFull(const struct Queue *pq) {
    if((pq->rear + 1) % (pq->capacity + 1) == pq->front)
        return 1;
    else
        return 0;
}
// 判断是否为空
int isEmpty(const struct Queue *pq) {
    return pq->front == pq->rear;
}
// 入队
int enQueue(struct Queue *pq, int x) {
    if (isFull(pq))
        return 0;
    else {
        pq->data[pq->rear] = x;
        // pq->rear++;
        pq->rear = (pq->rear + 1) % (pq->capacity + 1);
        return 1;
    }
}

// 出队
int deQueue(struct Queue *pq, int *px) {
    if (isEmpty(pq))
        return 0;
    else {
        *px = pq->data[pq->front];
        pq->front = (pq->front + 1) % (pq->capacity + 1);
        return 1;
    }
}

int main(int argc, char const *argv[])
{
    struct Queue q;
    init(&q, 5);
    enQueue(&q, 11);
    enQueue(&q, 22);
    enQueue(&q, 33);
    enQueue(&q, 44);
    enQueue(&q, 55);
    enQueue(&q, 66);
    int x;
    deQueue(&q, &x);
    printf("%d\n", x);
    deQueue(&q, &x);
    printf("%d\n", x);
    deQueue(&q, &x);
    printf("%d\n", x);
    deQueue(&q, &x);
    printf("%d\n", x);
    deQueue(&q, &x);
    printf("%d\n", x);
    deQueue(&q, &x);
    printf("%d\n", x);
    return 0;
}