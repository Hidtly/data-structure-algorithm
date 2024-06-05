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
/**
 * 按值查找
 * 1. 从第一个结点起，依次和e相比较
 * 2. 若有值与e相等的数据元素，则返回位置或地址
 * 3. 如果遍历链表都没有找到，则返回0或"null"
 */
Lnode *LocateElem_L(LinkList L, ElemType e)
{   //返回地址
    Lnode  *p;
    p = L->next;
    while (p && (p->data != e))
        p = p->next;
    return p;
}
int LocateElem_X(LinkList L, ElemType e) 
{   //返回序号
    Lnode *p;
    int j = 1;
    p = L->next;
    while (p && (p->data != e)) {
        p = p->next;
        j++;
    }
    if (p)
        return j;
    else
        return 0;
}
/**
 *  插入链表
 * 
 */
Status ListInsert_L(LinkList L, int i, ElemType e)
{
    Lnode *p, *s;
    p = L->next;
    int j = 0;
    while (p && j < i - 1){
        p = p->next; //寻找第i - 1个结点，p指向i - 1结点
        ++j;
    }
    if ( !p || j > i - 1 )
        return ERROR; //i大于表长+1或者小于1，插入位置非法
    s = (LinkList)malloc(sizeof(Lnode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}
//将线性表L中第i个元素删除
Status ListDelete_L(LinkList L, int i, ElemType *e) 
{
    Lnode *p, *q;
    p = L->next;
    int j = 0;
    while (p->next && j < i - 1) {
        p = p->next;//寻找第i个结点，并令p指向其前驱结点
        ++j;
    }
    if( !(p->next) || j > i - 1)
        return ERROR;//删除位置不合理
    q = p->next;//临时保持被删节点的地址以备释放
    p->next = q->next;//改变删除结点前驱结点的指针域
    *e = q->data;//保存删除结点的数据域
    free(q);//释放删除结点的空间
    return OK;
}