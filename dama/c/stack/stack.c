#include "stdio.h"
#include "stdlib.h"

// 使用数组来实现栈
struct Stack{
    int *data;              // 数据域
    int capacity;           // 容量
    int top;                // 栈顶
};

// 不考虑内存不够的情况 返回类型为void
// 初始化栈
void init(struct Stack *ps, int capacity) {
    ps->capacity = capacity; //栈的容量
    ps->data = (int *)malloc(sizeof(int) * capacity); // 分配内存 记得要释放！！！
    ps->top = 0;// 指向栈内最高元素之上的空位置
}

// 判断栈满
int isFull(const struct Stack *ps) {
    // 栈的容量是 0 ~ capacity-1
    return ps->top == ps->capacity;// 栈顶等于最后一个元素
}

// 判断栈空
int isEmpty(const struct Stack *ps) {
    return ps->top == 0; // 栈顶top == 0时 栈一定为空
}

// 压栈
int push(struct Stack *ps, int x){
    if(isFull(ps))
        return 0;// 栈满 返回0
    else {
        ps->data[ps->top++] = x; // 把x压入栈中 先使用top的值 在进行++
        return 1;
    }
}

// 弹栈
int pop(struct Stack *ps, int *px) {
    if(isEmpty(ps))
        return 0; // 栈空 返回0
    else {
#if 0
        ps->top--; //栈顶元素位置为 top-1
        *px = ps->data[ps->top];
#else
        *px = ps->data[--(ps->top)];
#endif
        return 1;
    }
}

// 查看栈顶元素
int top(const struct Stack *ps, int *px)
{
    if (isEmpty(ps))
        return 0; // 栈空 返回0
    else {
        *px = ps->data[ps->top - 1];
        return 1;
    }
}

// 销毁栈
void destroy(struct Stack *ps) {
    free(ps->data);
}

int main()
{
    struct Stack st;
    init(&st, 5);
    push(&st, 11);
    push(&st, 22);
    push(&st, 33);
    push(&st, 44);
    push(&st, 55);
    push(&st, 66);
    int x;
    pop(&st, &x);
    printf("%d\n", x);
    top(&st, &x);
    printf("%d\n", x);
    top(&st, &x);
    printf("%d\n", x);
    destroy(&st); //有始有终
    return 0;
}