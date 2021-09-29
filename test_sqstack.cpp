#include <iostream>
using namespace std;
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef int Status;

namespace SqStack{

typedef int SElemType;
typedef struct
{
    SElemType data[MAXSIZE];
    int top;
}SqStack;

Status InitStack(SqStack *S)
{
    S->top = -1;
    return OK;
}
Status Push(SqStack *S, SElemType e)
{
    if(S->top == MAXSIZE - 1)
    {
        return ERROR;
    }
    S->top++;
    S->data[S->top] = e;
    return OK;
}

Status Pop(SqStack *S, SElemType *e)
{
    if(S->top == -1)
        return ERROR;
    *e = S->data[S->top];
    S->top --;
    return OK;
}

void PrintSqStack(SqStack *S)
{
    for(int i = S->top; i > -1; --i)
    {
        cout<<S->data[i]<<endl;
    }
    cout<<"------------------"<<endl;
}

void test()
{
    SqStack s;
    SElemType a;
    InitStack(&s);
    Push(&s,1);
    Push(&s,2);
    Push(&s,3);
    PrintSqStack(&s);
    Pop(&s,&a);
    cout<<a<<endl;
    Pop(&s,&a);
    cout<<a<<endl;
    Pop(&s,&a);
    cout<<a<<endl;
    PrintSqStack(&s);
}
}
namespace LinkStacks{

typedef int SElemType;

typedef struct StackNode{
    SElemType data;
    struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack{
    LinkStackPtr top;
    int count;
}LinkStack;

Status InitStack(LinkStack *S)
{
    S->top = NULL;
    S->count = 0;
    return OK;
}

Status StackEmpty(LinkStack *S)
{
    if(S->top == NULL || S->count == 0)
        return OK;
    return ERROR;
}

Status Push(LinkStack *S, SElemType e)
{
    LinkStackPtr s= (LinkStackPtr) malloc(sizeof(StackNode));
    s->data = e;
    s->next = S->top;
    S->top = s;
    S->count++;
    return OK;
}

Status Pop(LinkStack *S, SElemType *e)
{
    LinkStackPtr s;
    if(StackEmpty(S))
        return ERROR;
    *e = S->top->data;
    s = S->top;
    S->top = S->top->next;
    free(s);
    S->count--;
    return OK;
}

Status PrintLinkStack(LinkStack *S)
{
    LinkStackPtr s;
    if(StackEmpty(S))
        return ERROR;
    s = S->top;
    cout<<" cout = "<<S->count<<endl;
    while(s)
    {
        cout<< s->data <<endl;
        s = s->next;
    }
    return OK;
}

void test()
{
    LinkStack s;
    SElemType a;
    InitStack(&s);
    Push(&s,1);
    Push(&s,2);
    Push(&s,3);
    PrintLinkStack(&s);
    Pop(&s,&a);
    cout<<a<<endl;
    Pop(&s,&a);
    cout<<a<<endl;
    Pop(&s,&a);
    cout<<a<<endl;
    PrintLinkStack(&s);
}

}

int main()
{
    SqStack::test();
    cout<<"-------------LinkStacks---------------"<<endl;
    LinkStacks::test();
    return 0;
}

