/**
 * @file StackNode.c
 * @author Hidtly (1773523578@qq.com)
 * @brief 使用链表实现栈
 * 链表的头指针就是栈顶
 * 不需要头结点
 * @version 0.1
 * @date 2024-06-20
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define CONDITION 1

typedef int SElemType;
typedef int Status;

typedef struct StackNode
{
    SElemType data;         // 数据域
    struct StackNode *next; // 指针域
} StackNode, *LinkStack;

// 链栈的初始化
// 栈顶指针置为空
Status InitStack(LinkStack *s)
{
    *s = NULL;
    //(*s)->next = NULL;
    return OK;
}

// 判断链栈是否为空
Status StackEmpty(LinkStack *s)
{
    if (*s == NULL)
        return TRUE;
    else
        return FALSE;
}

// 链栈的入栈
Status PushStack(LinkStack *s, SElemType e)
{
    LinkStack p = (LinkStack)malloc(sizeof(StackNode)); // 内存里分配新的空间
    p->data = e;                                        // 将新的结点数据域赋值为e p[data][next] -> p[e][next]
    p->next = *s;                                       // 将新结点插入栈顶中   p[e][next] -> p[e][s]
    *s = p;                                             // 修改栈顶指针            s -> p
    return OK;
}

// 链栈的出栈
Status PopStack(LinkStack *s, SElemType *e)
{
    if (StackEmpty(&s))
        return ERROR;
    LinkStack p = (LinkStack)malloc(sizeof(StackNode)); // 内存里分配新的空间
    *e = (*s)->data;
    p = *s;
    *s = (*s)->next;
    free(p);
    return OK;
}

// 取栈顶元素
int top(LinkStack *s) {
    if(StackEmpty(&s))
    return (*s)->data;
}
