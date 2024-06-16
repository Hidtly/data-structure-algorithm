#include "stdio.h"
#include "stdlib.h"
struct Node{
    int data;
    struct Node *next;
};//带头指针的链表

// typedef struct Node * LList;

// head pointer
//  |
// [ ] -> [ ] -> [ ]
// ??? -> [ ] -> [ ] -> [ ]

// head node
//  |
// [X] -> [ A ] -> [ ]
// [X] -> [ C ] -> [ A ] -> [ ]

void init(struct Node** phead){
    *phead = NULL;
}//初始化链表

int getLength(struct Node* head){
    int len = 0;
    while(head){
        len++;
        head = head->next;
    }
    return len;
}//求表长

void printList(struct Node* head){
    while (head) {
        printf("%d,", head->data);
        head = head->next;
    }
    putchar('\n');
}//遍历链表

struct Node* createNode(int x){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->next = NULL;
    t->data = x;
    return t;
}//创建结点函数

struct Node* findKth(struct Node * head, int k ){
    int count = 1;
    struct Node *p;
    p = head;
    while (p && count < k) {
        p = p->next;
        count++;
    }
    return p;
}

int insert(struct Node** phead, int k, int x) {
    //插入k 找k-1 不存在
    // k [ ] [ ] [ ] [ ]
    //    1   2   3   4
    //    p
    if ( k < 1) return 0; //位置不合法
    else if ( k == 1) {    //插入表头
        struct Node *t;
        t = createNode(x);
        t->next = *phead;
        *phead = t;
        return 1;
    } else {
        struct Node *p;
        p = findKth(*phead, k - 1);
        if (p) {
            struct Node *t;
            t = createNode(x);
            t->next = p->next;
            p->next = t;
            return 1;
        } else {
            return 0;
        }
    }
} //插入结点
int removeNode(struct Node** phead, int k, int *px){
    if (k < 1) return 0; // k < 1 位置不合法
    else if (k == 1) {   // k == 1 删除的是第一个结点时
        if (*phead) {    // 链表不空
            *px = (*phead)->data;
            *phead = (*phead)->next;
            return 1;
        }
        else return 0;
    }
    else {               // k > 1
        struct Node *p;
        p = findKth(*phead, k - 1);
        if(p == NULL || p->next == NULL) return 0; 
        // p == NULL没有第k-1个 p->next == NULL 没有第k个
        struct Node *t;
        t = p->next;
        p->next = t->next;
        *px = t->data;
        free(t);
        return 1;
    }
}

int main(void)
{
    struct Node *head;
    init(&head);
//  int k = getLength(head);

//  printf("%d\n", k);
    insert(&head, 1, 11); // h -> 11
    insert(&head, 1, 22); // h -> 22 -> 11
    insert(&head, 2, 33); // h -> 22 -> 33 -> 11
    insert(&head, 4, 44); // h -> 22 -> 33 -> 11 -> 44
    insert(&head, 6, 55); // 位置非法插入不成功
    printList(head);

    int x; //获取删除结点的元素值
    removeNode(&head, 5, &x);
    printf("%d\n", x);
    printList(head);
    return 0;
}