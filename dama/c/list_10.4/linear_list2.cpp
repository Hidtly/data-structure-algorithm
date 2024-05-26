#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100 

int i;

typedef int ElemType;
typedef struct LNode *List;                         /* 利用链表表存储 */
struct LNode{
    ElemType Data;
    List Next;
};
struct LNode L;
List Ptrl;

/* 求表长 */
int Length( List Ptrl ){
    List p = Ptrl;                                  /* p指向表的第一个节点 */
    int j = 0;
    while ( p ) {
        p = p->Next;
        j++;                                        /* p指向表的第 j 个节点 */
    }
    return j;    
} /* 遍历整个链表 O(n) */

/* 按序号查找 */
List FindKth( int K, List Ptrl ) {
    List p = Ptrl;
    int i = 1;
    while ( p != NULL && i < K ) {
        p = p->Next;
        i++;
    }
    if ( i == K ) return p;                         /* 找到第K个，返回指针 */
    else return NULL;                               /* 否则返回为空 */
}

/* 按值查找 */
List Find( ElemType X, List Ptrl ){
    List p = Ptrl;
    while ( p != NULL && p->Data != X ) 
        p = p->Next;
    return p;
}

/* 插入（第 i (1 <= i <= n+1)个位置上插入一个值为X的新结点） */
/* 构造新的结点，用s指向 */
/* 找到链表的第 i-1 结点，用p指向 */
/* 修改指针，插入结点（p之后插入新结点是s） */
List Insert( ElemType X, int i, List Ptrl ){
    List p, s;
    if( i == 1 ){                                   /* 新结点插入在表头 */
        s = ( List )malloc(sizeof( struct LNode )); /* 申请、装填新结点 */
        s->Data = X;
        s->Next = Ptrl;
        return s;/* 返回新表头指针 */
    }
    p = FindKth( i - 1, Ptrl );                     /* 寻找第 i-1 个结点 */
    if( p == NULL ){                                /*第 i-1 个不存在，不能插入*/
        printf(" 参数i错误 ");
        return NULL;
    }else{
        s = ( List )malloc(sizeof( struct LNode )); /* 申请、装填结点 */
        s->Data = X;
        s->Next = p->Next;                          /* 新结点插入在第 i-1 个结点后面 */
        p->Next = s;
        return Ptrl;
    }
} /* 平均查找次数为 O(n/2) */

/* 删除（第 i (1 <= i <= n+1)个位置上删除的结点） */
/* 找到链表的第 i-1 结点，用p指向 */
/* 再用指针s指向要被删除的节点（p的下一个节点） */
/* 最后释放s所指节点的空间free(s) */
List Delete( int i, List Ptrl ){
    List p,s;
    if( i == 1 ){                                   /* 若删除第一个结点 */
        s = Ptrl;                                   /* s指向第一个结点 */
        if( Ptrl != NULL ) Ptrl = Ptrl->Next;       /* 从链表中删除结点 */
        else return NULL;
        free(s);                                    /* 释放被删除的结点 */
        return Ptrl;
    }
    p = FindKth( i-1, Ptrl );                       /* 寻找第 i-1 个结点 */
    if( p == NULL ){
        printf(" 第%d个结点不存在 ", i-1);  return NULL;
    }else if( p->Next == NULL ){
        printf(" 第%d个结点不存在 ", i);    return NULL;
    }else {
        s = p->Next;                                /* s指向第 i 个结点 */
        p->Next = s->Next;                          /* 从链表中删除结点 */
        free(s);                                    /* 释放被删除的结点 */
        return Ptrl;
    }
} /* 平均查找次数为 O(n/2) */