#include "stdio.h"
#include "stdlib.h"

//存储学生学号、姓名、成绩的单链表
typedef struct student{
    char num[8];
    char name[8];
    int score;
    struct student *next;
}LnodeStu, *LinkListStu;

//为了统一链表的操作，通常这样定义
typedef struct {
    char num[8];
    char name[8];
    int score;
} ElemType;
typedef struct Lnode {
    ElemType data;
    struct Lnode *next;
} Lnode, *LinkList;