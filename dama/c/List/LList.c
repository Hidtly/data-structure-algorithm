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
}//遍历链表

struct Node* createNode(int x){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->next = NULL;
    t->data = x;
    return t;
}//创建结点函数

int insert(struct Node** phead, int k, int x) {
    //插入k 找k-1 不存在
    // k [ ] [ ] [ ] [ ]
    //    1   2   3   4
    //    p
    struct Node *p;
    int count = 1;
    p = *phead;
    while (p && count < k - 1){
        p = p->next;
        count++;
    }
    if(p){
        struct Node *t;
        t = createNode(x);
        t->next = p->next;
        p->next = t;
        return 1;
    } else {
        return 0;
    }
}

int main(void)
{
    struct Node *head;
    init(&head);
//  int k = getLength(head);

//  printf("%d\n", k);
    insert(&head, 1, 11);
    insert(&head, 1, 22);
    printfList(head);
    return 0;
}