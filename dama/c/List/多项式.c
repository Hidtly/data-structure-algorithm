#include "stdio.h"
#include "stdlib.h"

typedef struct PNode{
    float coef; // 系数
    int expn;   // 指数
    struct PNode *next;
} PNode, *Polynomial;

void CreatePolyn(Polynomial *p, int n){
    PNode *p;
    *p = (Polynomial)malloc(sizeof(PNode));
    (*p)->next = NULL;
    for (int i = 1; i <= n; i++) {
        Polynomial s= (Polynomial)malloc(sizeof(PNode));
        scanf("%lf", &(s->coef));
        scanf("%d", &(s->coef));
        Polynomial q = (*p)->next; // q为指向比pew->exponent大的节点
        Polynomial pre = (*p);     // pre指向q的直接前驱节点
        while (q && q->expn < s->expn) { // 第1次for循环不会执行
            // 直到找到一个结点的expn大于s->expn，如果没有找到q指向NULL
            pre = q;
            q = q->next;
        }
        s->next = q; // 因为q->expn > s->expn
        pre->next = s;
    }
}