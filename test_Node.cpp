#include <iostream>
using namespace std;
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef int Status;

//--------------------------线性表的单链表存储结构---------------------------
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;

//初始化
Status ListInit(LinkList L)
{
    cout<<"ListInit"<<endl;
    L->next = nullptr;
    L->data = 0;
    return OK;
}
// 返回链表中的指定值
Status GetElem(LinkList L, int i, ElemType *e)
{
    int j;
    LinkList p;
    p = L->next;
    j = 1;
    while(p && j < i)
    {
        p = p ->next;
        ++j;
    }
    if( !p || j > i )
        return ERROR;
    *e = p->data;
    return OK;
}

//插入
Status ListInsert(LinkList *L, int i, ElemType e)
{
    cout<<"ListInsert"<<endl;
    int j;
    LinkList p,s;
    p = *L;//为什莫要传入指针的指针，但用指针赋值不行吗
    j = 1;
    while(p && j < i)
    {
        p = p->next;
        ++j;
    }
    if(!p || j > i)
        return ERROR;
    s = (LinkList) malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}
//删除
Status ListDelete(LinkList *L ,int i, ElemType *e)
{
    int j;
    LinkList p,q;
    p = *L;
    j = 1;
    while(p->next && j < i)
    {
        p = p->next;
        ++j;
    }
    if(!(p->next) || j > i)
        return ERROR;
    q = p->next;
    p ->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}
//打印
Status ListPrint(LinkList *L)
{
    LinkList p;
    p = *L;
    int len = 0;
    while(p)
    {
        cout<<p->data<<endl;
        p = p->next;
        len++;
    }
    cout<<"len = " <<len<<endl;
    return OK;
}
//获取有效链表长度
Status ListLength(LinkList *L,int *len)
{
    LinkList p=*L;
    int countNum = 0;
    while(p)
    {
        ++(countNum);
        p = p->next;
    }
    *len = countNum;
    return OK;
}
//创建单链表头插法
void CreateListHead(LinkList *L, int n)
{
    cout<<"CreateListHead"<<endl;
    LinkList p;
    int i;
    srand(time(0));
    *L = (LinkList) malloc(sizeof(Node));
    (*L)->next = NULL;
    for(i = 0; i < n;++i)
    {
        p = (LinkList) malloc(sizeof(Node));
        p->data = rand()%100 + 1;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}
//尾插法
void CreateListTail(LinkList *L, int n)
{
    cout<<"CreateListTail"<<endl;
    LinkList p,q;
    int i;
    srand(time(0));
    *L = (LinkList) malloc (sizeof(Node));
    (*L)->next = NULL;
    q = *L;
    for(i = 0;i < n; ++i)
    {
        p = (LinkList) malloc(sizeof(Node));
        p->data = rand()%100 + 1;
        q->next = p;
        q = p;
    }
    q->next = NULL;
}
//整链表删除
Status ClearList(LinkList *L)
{
    LinkList p,q;
    p = (*L) ->next;
    while(p)
    {
        q = p ->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}
void test()
{
    Node s;
    LinkList s1 = &s;
    ListInit(&s);
    cout<<"test"<<endl;
    ListInsert(&s1,1,1);
    ListInsert(&s1,1,2);
    ListInsert(&s1,1,3);
    ListPrint(&s1->next);
    int len = 0;
    ListLength(&s1->next,&len);
    cout<<"length = "<<len<<endl;
    ElemType x;
    ListDelete(&s1,1,&x);
    cout<<"e = "<<x<<endl;
    ListPrint(&s1->next);
    x = 0;
    ListDelete(&s1,2,&x);
    cout<<"e = "<<x<<endl;
    ListPrint(&s1->next);
}
void test02()
{
    LinkList s;
    //CreateListHead(&s,10);
    CreateListTail(&s,10);
    ListPrint(&s->next);
    int len = 0;
    ListLength(&s->next,&len);
    cout<<"length = "<<len<<endl;
    ClearList(&s);
    len = 0;
    ListLength(&s->next,&len);
    cout<<"length = "<<len<<endl;
}
int main()
{
//    test();
    test02();
    return 0;
}

