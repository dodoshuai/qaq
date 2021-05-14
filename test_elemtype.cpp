#include <iostream>
#include <string>
using namespace std;

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef int Status;

//顺序表结构
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SqList;
//初始化
Status ListInit(SqList *L)
{
    L->length = 0;
    return OK;
}
//获取对应元素  如果获取出错则返回ERROR
Status GetElem(SqList *L, int i, ElemType *e)
{
    if (L->length == 0 || i < 1 || i > L->length)
        return ERROR;
    *e = L->data[i-1];
    return OK;
}
//插入
Status ListInsert(SqList *L, int i, ElemType e)
{
    cout<<"----------"<<e<<"---------"<<endl;
    int k;
    if(L->length == MAXSIZE)
        return ERROR;
    if(i<1 || i > L->length + 1)
        return ERROR;
    if(i <= L->length)
    {
        //从后向前，将插入点之后的数据向后集体移动一格
        for(k = L->length - 1 ; k>=i-1; k--)
            L->data[k+1] = L->data[k];
    }
    L->data[i-1] = e;
    L->length++;
    return OK;
}
//删除
Status ListDelete(SqList *L, int i, ElemType *e)
{
    int k;
    if(L->length == 0)
        return ERROR;
    if(i < 1 || i > L->length)
        return ERROR;
    *e = L->data[i-1];
    if(i < L->length)
    {
        for(k=i; k < L->length; ++k)
            L->data[k-1] = L->data[k];
    }
    L->length--;
    return OK;
}
//打印顺序存储表
Status ListPrint(SqList *s)
{
    for(int i=0;i<s->length;++i)
        cout<<s->data[i]<<endl;
    cout<<"length = "<<s->length<<endl;
    return OK;
}
void test01()
{
    SqList s;
    //优先初始化，如果是类，记得检查构造函数，对于手动初始化
    //的成员，必须及时初始化
    ListInit(&s);
    ElemType a = 6;
    ListInsert(&s,s.length+1, 6);
    ListInsert(&s,s.length+1, 7);
    ListInsert(&s,s.length+1, 8);
    ListInsert(&s,3,9);
    ListPrint(&s);
    int e=0;
    ListDelete(&s,s.length,&e);
    ListPrint(&s);
    cout<<e<<endl;
    e=0;
    GetElem(&s,s.length-2,&e);
    cout<<e<<endl;

}



int main()
{
    test01();
    return 0;
}

