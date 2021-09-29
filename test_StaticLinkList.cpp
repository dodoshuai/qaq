#include <iostream>
#include <string>
using namespace std;
#define MAXSIZE 1000
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef int Status;

typedef struct {
    ElemType data;
    int cur;
} Component,StaticLinkList[MAXSIZE];

Status InitList(StaticLinkList space)
{
    int i;
    for (i = 0; i<MAXSIZE-1; ++i)
        space[i].cur = i + 1;
    space[MAXSIZE-1].cur = 0;
    return OK;
}

//返回L中数据元素个数
int ListLength(StaticLinkList L)
{
    int j = 0;
    int i = L[MAXSIZE-1].cur;
    while(i)
    {
        i = L[i].cur;
        j++;
    }
    return j;
}

//自定义分配空间
int Malloc_SSL(StaticLinkList space)
{
    //未分配下标由此保存
    int i = space[0].cur;
    if(space[0].cur)
        space[0].cur = space[i].cur;
    return i;
}
//将下表为k的空闲结点回收到备用链表
void Free_SSL(StaticLinkList space, int k)
{
    space[k].cur = space[0].cur;
    space[0].cur = k;
}
//在L中第i个元素之前插入新的数据元素
Status ListInsert(StaticLinkList L, int i , ElemType e)
{
    cout<<"ListInsert"<<endl;
    int  j,k,l;
    k = MAXSIZE - 1;
    if(i<1 || i > ListLength(L) + 1)
        return ERROR;
    // 获取未分配空间下标
    j = Malloc_SSL(L);
    if(j)
    {
        // 在寻找到的空间中存入数据
        L[j].data = e;
        //寻找当前链表的固定位置
        for(l = 1; l <= i-1; l++)
            k = L[k].cur;
        //将数据插入链表的固定位置
        L[j].cur = L[k].cur;
        L[k].cur = j;
        return OK;
    }
    return OK;
}
//删除在L中第i个数据元素
Status ListDelete(StaticLinkList L, int i)
{
    int j, k;
    if(i < 1 || i > ListLength(L))
        return ERROR;
    k = MAXSIZE - 1;
    //寻找到固定坐标
    for(j = 1; j <= i -1; j++)
        k = L[k].cur;
    //进行链表中固定点的删除重连
    j = L[k].cur;
    L[k].cur = L[j].cur;
    //将空白空间加入备用链表
    Free_SSL(L, j);
    return OK;
}

// 打印已添加的数据元素
void ListPrint(StaticLinkList L)
{
    cout<<"-----------------------"<<endl;
    int j, k;
    k = L[MAXSIZE - 1].cur;
    for(j = 0;j < ListLength(L);++j)
    {
        cout<<L[k].data<<endl; 
        k = L[k].cur;
    }
}
// 打印已添加的数据元素
void ListPrintCur(StaticLinkList L)
{
    cout<<"-----------------------"<<endl;
    int j, k;
    //k = L[MAXSIZE - 1].cur;
    k = MAXSIZE - 1;
    for(j = 0;j <= ListLength(L);++j)
    {
        cout<<L[k].cur<<endl; 
        k = L[k].cur;
    }
    cout<<"---------f----------"<<endl;
    for(int i=0; i < 10; ++i)
        cout<<L[i].cur<<endl;
}
void test()
{
    StaticLinkList t;
    InitList(t);
    ListPrintCur(t);
    ListInsert(t,1,1);
    ListInsert(t,1,2);
    ListInsert(t,3,3);
    ListInsert(t,2,4);
    ListPrint(t);
    ListPrintCur(t);
    ListDelete(t,2);
    ListPrint(t);
    ListPrintCur(t);
}
int main()
{
    test();
    return 0;
}

