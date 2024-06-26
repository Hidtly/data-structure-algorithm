/*
题目描述
用程序简单模拟一个单队列多窗口的排队模式:
设某银行有一个固定能容纳 N 个顾客的等候区，顾客想进银行，若等候区有空则可进，否则被拒绝进入。
每当银行柜员叫号时，等候区中最先进入的顾客离开等候区前往柜台办理业务，若叫号时等候区无人，则此次叫号作废。

输入格式:
第一行输入一个不大于20的正整数 N，表示银行等候区能容纳的人数，接下来用若干行表示依时间顺序先后发生的“顾客想进银行”或“叫号”事件，格式分别是:

顾客想进银行，用In <id>表示，其中 <id>是顾客编号，为不大于100000的正整数:。
叫号，用calling表示。
最后一行是一个  # 符号，表示输入结束。

注意:
1.题目输入保证每个顾客的编号是独一无二的，即:不会出现想进银行的顾客与已经在等候区的顾客编号相同的情况。
2.保证后一个事件定在前一个事件完成之后才发生，即:不需要考虑事件之间的“同步”问题。

输出格式:
    对于输入的每个事件，按同样顺序在一行内输出事件的结果，格式分别是:
        顾客想进银行，若顾客进入，则输出 <id> joined.Total:<t>其中 <id>是该顾客的编号，<t>是顾客进入后，等候区的人数
        顾客想进银行，若因等候区满而被拒绝，则输出<id>rejected.其中<id>是该顾客的编号
        叫号，若有顾客前往柜台，则输出<id>ca1led.rota1:<t>其中 <id>是该顾客的编号，<t>是顾客去柜台后，等候区的人数等候区
        叫号，等候区无人，则输出No one!

输入样例：
3
In 101
In 102
In 103
In 104
calling
In 105
calling
calling
calling
calling
#

输出样例：
101 joined.Total:1
102 joined.Total:2
103 joined.Total:3
104 rejected
101 called.Total:2
105 joined.Total:3
102 joined.Total:2
103 joined.Total:1
105 joined.Total:0
No one!

*/
#include "stdio.h"
#include "stdlib.h"



struct Queue{
    int *data;
    int capacity;
    int front;
    int rear;
    int size;
};

void init(struct Queue *pq, int capacity) {
    pq->capacity = capacity;
    pq->data = (int *)malloc(sizeof(int) * (capacity + 1));
    pq->front = pq->rear = pq->size = 0;
}

int isFull(const struct Queue *pq) {
    return (pq->rear + 1) % (pq->capacity + 1) == pq->front;
}
int isEmpty(const struct Queue *pq) {
    return pq->front == pq->rear;
}
int enQueue(struct Queue *pq, int px) {
    if(isFull(pq))
        return 0;
    else {
        pq->data[pq->rear] = px;
        pq->rear = (pq->rear + 1) % (pq->capacity + 1);
        pq->size++;
        return 1;
    }
}
int deQueue(struct Queue *pq, int *px) {
    if (isEmpty(pq))
        return 0;
    else {
    *px = pq->data[pq->front];
    pq->front = (pq->front + 1) % (pq->capacity + 1);
    pq->size--;
    return 1;
    }
}
int main(void) {
    int N ;
    scanf("%d", &N);
    struct Queue q;
    init(&q, N);
    char op[20];
    int id;
    scanf("%s", op);
    while (op[0] != '#') {
        if(op[0] == 'I') { // In<id>
            scanf("%d", &id);
            if( isFull(&q) ) { //队列满了 rejected
                printf("%d rejected.\n", id);
            } else {
                enQueue(&q, id);
                printf("%d joined. Total:%d\n", id, q.size);
            }
        } else { // Calling
            if ( isEmpty(&q) ) { //等候区无人
                printf("No one!\n");
            } else {
                deQueue(&q, &id);
                printf("%d called. Total:%d\n", id, q.size);
            }
        }
        scanf("%s", op);
    }
    return 0;
}