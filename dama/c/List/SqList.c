#include <stdio.h>
#include <stdlib.h>
#include <define.h>

#define LIST_INIT_SIZE 100

#if CONDITION
// 数组动态分配
typedef struct {
    ElemType *elem;
    int length;
} SqList;

#else
// 数组静态分配
typedef struct {
    ElemType elem[LIST_INIT_SIZE];
    int length;
} SqList;
#endif
//(*L).elem = L->elem
// 线性表L 初始化
Status InitList_Sq(SqList *L)
{
    L->elem = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    if (!L->elem)
        exit(OVERFLOW); //存储分配失败
    L->length = 0;
    return OK;
}
// 销毁线性表L
void DestroyList(SqList *L)
{
    if (L->elem)
        free(L->elem);
}
// 清空线性表L
void ClearList(SqList *L)
{
    L->length = 0;
}
// 求线性表L的长度
Status GetLength(SqList *L)
{
    return (L->length);
}


// 判断线性表L是否为空
Status IsEmpty(SqList *L)
{
    if (L->length == 0)
        return TRUE;
    else
        return FALSE;
}

// 取线性表L 第i个元素的内容
Status GetElem(SqList *L, int i, ElemType *e)
{
    if (i < 1 || i > L->length)
        return ERROR;      //判断i值是否合理 不合理返回ERROR
    *e = L->elem[i - 1];    //第i - 1个单元存着第i个数据
    return OK;
}
// 在线性表L中查找值为e 的数据元素，返回其序号（是第几个元素）
Status LocateElem(SqList *L, ElemType e)
{
#if 0
    for (int i = 0; i < L->length; i++)
    if (L->elem[i] == e)
        return i + 1; //查找成功，返回其序号
    return FALSE;     //查找失败，返回false
    /** 
     * O(n)
     */
#else
    int i = 0;
    while (i < L->length && i > L->elem[i] != e)
        i++;
    if (i < L->length) // 查找成功，返回其序号
        return i + 1;  // 查找失败，返回false
    return FALSE;
    /**
     * O(n)
     */
#endif
}
/**
 * 插入
 * 1.判断插入位置是否合法
 * 2.判断线性表是否已满，若已满返回ERROR
 * 3.将第n至第i位的元素依次向后移一位，空出第i个位置
 * 4.将要插入的新元素e放入第i个位置
 * 5.表长加1，插入成功返回OK
 */
Status Insert(SqList *L, int i, ElemType e)
{
    if (i< 0 || i > L->length + 1) //i值不合法
        return ERROR;
    if (L->length == LIST_INIT_SIZE) //当前存储空间已满
        return ERROR;
    for (int j = L->length - 1; j >= i - 1; j-- ) {
        L->elem[j + 1] = L->elem[j];//插入位置及之后的元素往后移
    }
    L->elem[i - 1] = e;//将新元素e放入第i个位置
    L->length++;//表长增1
    return OK;
}
/**
 * 删除
 * 1.判断删除位置是否合法(1 <= i <= n)
 * 2.将第i + 1至第n位的元素依次向后前一位
 * 3.表长减1，删除成功返回OK
 */
Status Delete(SqList *L, int i)
{
    if (i < 0 || i > L->length + 1) // i值不合法
        return ERROR;
    for (int j = i; j <= L->length - 1; j++)
        L->elem[j - 1] = L->elem[j]; //被删除元素之后的元素前移
    L->length--;//表长减1
    return OK;
}
//有序表的合并
void MergeList_Sq(SqList *La, SqList *Lb, SqList *Lc)
{
    ElemType *pa, *pb, *pc, *pa_last, *pb_last;
    pa = La->elem;                       //指针pa初值指向表La的第一个元素
    pb = Lb->elem;                       //指针pb初值指向表Lb的第一个元素
    Lc->length = La->length + Lb->length;//新表长度为量表的长度之和
    Lc->elem = (ElemType *)malloc(sizeof(ElemType) *Lc->length);//为合并后的新表分配一个数组空间
    pc = Lc->elem;                       //指针pc指向新表的第一个元素
    pa_last = La->elem + La->length - 1; //指针pa_last指向La表的最后一个元素
    pb_last = Lb->elem + Lb->length - 1; //指针pb_last指向Lb表的最后一个元素
    while (pa <= pa_last && pb < pa_last)//两个表都非空
    {
        if (*pa <= *pb)                  //依次摘取两表中值较小的结点
            *(pc++) = *(pa++);
        else
            *(pc++) = *(pb++);
    }
    while (pa <= pa_last)
        *(pc++) = *(pa++);              // Lb表已经到达了表尾，将La中的剩余元素加入Lc
    while (pb <= pb_last)
        *(pc++) = *(pb++);              // La表已经到达了表尾，将Lb中的剩余元素加入Lc
}