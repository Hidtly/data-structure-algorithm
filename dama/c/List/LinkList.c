#include "stdio.h"
#include "stdlib.h"
#include "define.h"


typedef struct Lnode {  //声明结点的类型和指向结点的指针类型
    ElemType      data; //结点的数据域
    struct Lnode *next; //结点的指针域
}Lnode, *LinkList;      //LinkList为指向结构体Lnode的指针类型

// 定义链表L：LinkList L;
// 定义结点指针p: Lnode *p *s √  LinkList p × ;
// p = L; p指向头结点
// s = L->next s指向首元结点
// p = p->next p指向下一结点

/* 链表初始化 */ 
Status InitList_L(LinkList *L) 
{
    (*L) = (LinkList)malloc( sizeof(Lnode) );
    (*L)->next = NULL;
    return OK;
}

/* 判断链表L是否空 */ 
Status ListEmpty(LinkList L) 
{
    if (L->next)
        return FALSE;
    else
        return TRUE;
}

/* 销毁链表L */ 
Status DestroyList_L(LinkList *L)
{
    LinkList p;
    while ((*L)) {
        p = *L;
        (*L) = (*L)->next;
        free(p);
    }
    *L = NULL;
    return OK;
}

/* 清空单链表L */ 
Status ClearList_L(LinkList *L) 
{
    Lnode *p, *q;
    p = (*L)->next;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}
/* 求单链表的表长 */ 
Status ListLength_L( LinkList L )
{
    LinkList p;
    p = L->next;
    int i = 0;
    while (p) {
        i++;
        p = p->next;
    }
    return i;
}
/**
 *   按序号查找
 * 1.从第一个结点(L->next)顺链扫描，用指针p指向当前扫描到的结点，p初值p = L->next
 * 2.j做计算器，累计当前扫描过的结点，j初值为1
 * 3.当p指向扫描的下一结点时，j++
 * 4.当 j==i时，p所指的结点就是要找的第i个结点 
 */
Status GetElem_L(LinkList L, int i, ElemType *e)
{
    LinkList p;
    p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if ( !p || j > i)
        return ERROR;
    *e = p->data;
    return OK;
}