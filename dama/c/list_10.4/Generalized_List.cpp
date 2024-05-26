#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100 

int i;


typedef int ElemType;
typedef struct GNode *GList;

/// @brief 广义表
struct GNode{
    int Tag;/* 标志域：0 表示结点是单元素，1 表示结点是广义表 */
    union {/* 字表指针域 SubList 与单元素数据域Data复用，共用储存空间 */
        ElemType Data;
        GList SubList;
    } URegion;
    GList Next; /* 指向后继结点 */
};
typedef __int8 s;