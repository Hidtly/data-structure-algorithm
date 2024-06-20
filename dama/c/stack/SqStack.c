/**
 * @file SqStack.c
 * @author Hidtly (1773523578@qq.com)
 * @brief 使用双指针实现的栈
 * @version 0.1
 * @date 2024-06-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "stdio.h"
#include "stdlib.h"


#define MAXSIZE      100
#define TRUE         1
#define FALSE        0
#define OK           1
#define ERROR        0
#define INFEASIBLE  -1
#define OVERFLOW    -2
#define CONDITION    1

typedef int SElemType;
typedef int Status;

typedef struct {
    SElemType *base; // 栈底指针
    SElemType *top;  // 栈顶指针
    int stackSize;   // 栈的容量
} SqStack;

// 构造一个空栈
Status InitStack(SqStack *s) {
    s->base= (SElemType *)malloc(sizeof(SElemType) * MAXSIZE); // 内存分配空间
    if (!s->base) return OVERFLOW; // 分配内存失败
    s->top = s->base; // 栈顶指针等于栈底指针
    s->stackSize = MAXSIZE;
    return OK;
}

// 判断栈是否为空
Status StackEmpty(const SqStack *s) {
    if(s->base == s->top)
        return TRUE;
    else
        return FALSE;
}

// 判断栈是否满了
Status StackFull(const SqStack *s) {
    if((s->top - s->base) == s->stackSize)
        return 1;
    else
        return 0;
}

// 求顺序栈的长度
int StackLength(const SqStack *s) {
    return s->top - s->base;
}

// 清空顺序栈
Status ClearStack(SqStack *s) {
    if(StackEmpty(s))
        s->top = s->base;
    return OK;
}

// 销毁顺序栈
Status DestroyStack(SqStack *s) {
    if(StackEmpty(s)) {
        free(s->base); // 释放内存
        s->stackSize = 0; // 长度设为零
        s->base = s->top = NULL; // 指针设为空
    }
    return OK;
}

// 顺序栈的入栈
Status PushStack(SqStack *s, SElemType e) {
    if(StackFull(s))
        return ERROR;
    else
        // *s->top = e;
        //  s->top++;
        *s->top++ = e;
    return OK;
}

// 顺序栈的出栈
Status PopStack(SqStack *s, SElemType *e) {
    if(StackEmpty(s))
        return ERROR;
    else
        *e = *(--(s->top));
    // --s->top;
    // e = *s->top;
    return OK;
}

// 查看栈顶元素
int top(const SqStack *s, SElemType *x)
{
    if (StackEmpty(s))
        return 0; // 栈空 返回0
    else{
        *x = *((s->top)-1);
        return OK;
    }
}
int main(int argc, char const *argv[])
{
    SqStack st;
    InitStack(&st);
    PushStack(&st, 11);
    PushStack(&st, 22);
    PushStack(&st, 33);
    PushStack(&st, 44);
    PushStack(&st, 55);
    PushStack(&st, 66);
    while (!StackEmpty(&st))
    {
        SElemType e;
        PopStack(&st, &e);
        printf("%d", e);
        putchar('\n');
    }
    int x ;
    PushStack(&st, 11);
    top(&st, &x);
    printf("%d", x);
    putchar('\n');
    PushStack(&st, 608);
    top(&st, &x);
    printf("%d", x);
    return 0;
    
}
