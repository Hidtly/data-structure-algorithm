#include "stdio.h"
#include "stdlib.h"
#include "define.h"

typedef struct DuLNode{
    ElemType data;
    struct DuLNode *prior, *next;
} DuLNode, *DuLinkList;

// 双向链表的对称性
//p->prior->next = p = p->prior->next;

//在带头结点的双向链表L中第i个位置之前插入元素e
Status ListInsert_DuL(DuLinkList L, int i, ElemType e)
{
    DuLinkList p;
    if( !(p = GetElemP_Dul(L, i)))
        return ERROR;
    DuLNode *s = (DuLNode *)malloc(sizeof(DuLNode));
    s->data = e;
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    return OK;
}

// 删除带头结点的双向链表L中第i个位置
Status ListDelete_DuL(DuLinkList L, int i, ElemType *e)
{
    DuLinkList p;
    if (!(p = GetElemP_Dul(L, i)))
        return ERROR;
    *e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return OK;
}

Status GetElemP_Dul(DuLinkList L, int i)
{
    DuLinkList p;
    p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return ERROR;
    return OK;
}