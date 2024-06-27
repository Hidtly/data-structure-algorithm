#include "stdio.h"

enum color { red, green, yellow };

int main() {
    enum color t = 0;
    scanf("%d", &t);
    f(t);
    return 0;
}



void f(enum color c) {
    printf("%d\n", c);
}