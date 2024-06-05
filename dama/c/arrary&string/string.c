#include "stdio.h"
#include "string.h"
int main()
{
    char *str = "hello world";
    printf("%p\n", str);
    char *s2 = "hello world";
    printf("%p\n", s2);

    char s3[] = "hello";
    printf("%ld\n", sizeof s3);

}