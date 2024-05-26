#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100                             


int i;

typedef int ElemType;
typedef struct LNode *List;                     /* 利用数组表存储 */

struct LNode {
        ElemType Data[ MAXSIZE ];               /* 定义线性表长度 */
        int Last;                               /* 线性表最后一个元素 */
};
struct LNode L;
List Ptrl;
//访问下标为I的元素:  //L.Data[i] | Ptrl->Data[i];
//线性表的长度: L.Last + 1 | Ptrl->Last + 1;


int main(int argc, char const *argv[]) {
    return 0;
}

/* 初始化（建立空的顺序表） */
List MakeEmpty( )
{
    List Ptrl;
    Ptrl = ( List ) malloc ( sizeof (struct LNode) );
    Ptrl->Last = -1;
    return Ptrl;
}

/* 查找 */
int Find( ElemType X, List Ptrl ){
    int i = 0;
    while( i <= Ptrl->Last && Ptrl->Data[i] != X )
        i++;
    if( i > Ptrl->Last ) return -1;             /* 如果没有找到，返回-1 */
    else return i;                              /* 找到后返回的是储存位置 */
    
}

/* 插入（第 i (1 <= i <= n+1)个位置上插入一个值为X的新元素） */
void Insert( ElemType X, int i, List Ptrl ){
    int j;
    if( Ptrl->Last == MAXSIZE - 1 ){            /* 表空间已经满了，不能插入 */
        printf("表满");
        return ;
    }
    if( i < 1 || i > Ptrl->Last+2 ){            /* 判断插入位置的合法性 */
        printf("位置不合法");
        return ;
    }
    for( j = Ptrl->Last; j >= i - 1; j-- )     
        Ptrl->Data[ j + 1 ] = Ptrl->Data[ j ];  /* 把Ai ~ An倒序向后移动 */
    Ptrl->Data[ i - 1 ] = X;                    /* 将新元素X插入 */
    Ptrl->Last++;                               /* Last仍指向最后的元素 */
    return ;
} /* 先移动 后插入 */

/* 删除（第 i (1 <= i <= n+1)个位置上删除的元素） */
void Delete( int i, List Ptrl ){
    int j;
    if( i < 1 || i > Ptrl->Last+1 ){            /* 判断空表和位置的合法性 */
        printf("不存在第%d个元素", i);
        return ;
    }
    for( j = i ; j <= Ptrl->Last; j++ )
        Ptrl->Data[ j - 1 ] = Ptrl->Data[ j ];  /* 把Ai ~ An顺序向前移动 */
    Ptrl->Last--;                               /* Last仍指向最后的元素 */
    return ;                                    /* (n-1) / 2 */
} /* 用后一位的值覆盖前一位的值 */