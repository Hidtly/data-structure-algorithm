#include "stdio.h"
#include "stdlib.h"

#define MAX 50


struct Stack {
    int *data;
    int top;
    int capacity;
};

int init(struct Stack *s) {
    s->top = 0;
    s->capacity = MAX;
    s->data = (int *)malloc(sizeof(int) * MAX);
}
int push(struct Stack *s, int e){
    if(s->top == s->capacity)
        return 0;
    else {
        s->data[s->top++] = e;
        return 1;
    }
}

int pop(struct Stack *s, int *e) {
    if (s->top == 0)
        return 0;
    else {
       *e = s->data[--(s->top)];
       return 1;
    }
}
int cal(char str[], int num1, int num2) {

}
int changeNumber(char str[]) {
    int num1, num2;
    struct Stack st;
    init(&st);
    int i = 0;
    int number;
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            if (str[i] >= '0' && str[i] <= '9') {
                number = 0;
                while (str[i] != ' ' && str[i]) {
                    number = number * 10 + (str[i] - '0');
                    i++;
                } // while
                push(&st, number);
            } // if
            else {
                pop(&st, &num2);
                pop(&st, &num1);
                switch (str[i])
                {   
                case '+':
                    num1 += num2;
                    break;
                case '-':
                    num1 -= num2;
                    break;
                case '*':
                    num1 *= num2;
                    break;
                case '/':
                    num1 /= num2;
                    break;
                default:
                    num1 %= num2;
                    break;
                } // switch
                push(&st, num1);
            } // else
        } // if
        i++;
        } // while
        pop(&st, &num1);
        return num1;
} // changNumber()

void test()
{
    char arr[] = "9 3 1 - 3 * +10 2 / +";
    int ans = changeNumber(arr);
    printf("%s = %d", arr, ans);
}

int main(void)
{
    test();
    return 0;
}
