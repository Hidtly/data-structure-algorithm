#include "stdio.h"

#define MAX 10

struct SList{
    int data[10];
    int length;
};
void init(struct SList* p){
    p->length = 0;
}
void printfList(const struct SList* p){
    for (int i = 0; i < p->length; i++)
    {
        printf("%d,", p->data[i]);
    }
    putchar('\n');
}
int insert(struct SList* p, int k, int x){
    if ((k < 0 || k > p->length )|| (p->length == MAX))
        //((k < 0 || k > p->length ) ： k的位置不合法
        // (p->length == MAX))  ： 表满
        return 0;
    else {
        for (int i = p->length - 1; i >= k ; i--){
            p->data[i + 1] = p->data[i];
        }
        p->data[k] = x;
        p->length++;
        return 1;
    }
}
int delete( struct SList* p, int k, int *px){
    if(k < 0 || k >= p->length)
        return 0;
    else {
        *px = p->data[k];
        for (int i = k + 1 ; i < p->length; i++) {
            p->data[i - 1] = p->data[i];
        }
        p->length--;
        return 1;
    }
}
int main(int argc, char const *argv[])
{
    struct SList a;
    init(&a);
    insert(&a, 0, 11);
    insert(&a, 0, 22);
    insert(&a, 1, 33);
    printfList(&a);
    int x;
    delete(&a, 1, &x);
    delete(&a, 0, &x);
    printfList(&a);
    return 0;
}
