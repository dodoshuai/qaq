#include <iostream>
using namespace std;
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef int Status;

typedef int SElemType;
typedef struct{
    SElemType data[MAXSIZE];
    int head;
    int tail;
}t_Queue;
typedef t_Queue *QueuePtr;

Status InitQueue(QueuePtr Q)
{
    Q->head = 0;
    Q->tail = 0;
    return OK;
}

Status EnQueue(QueuePtr Q, SElemType e)
{
    if((Q->tail+1)%MAXSIZE == Q->head)
        return ERROR;
    Q->data[Q->tail] = e;
    Q->tail = (Q->tail+1) % MAXSIZE;
    return OK;
}

Status DeQueue(QueuePtr Q, SElemType *e)
{
    if(Q->head == Q->tail)
        return ERROR;
    *e = Q->data[Q->head];
    Q->head = (Q->head + 1) % MAXSIZE;
    return OK;
}

Status ClearQueue(QueuePtr Q)
{
    if(Q->head != 0 || Q->head != Q->tail)
        Q->head = Q->tail = 0;
    return OK;
}

Status QueueEmpty(QueuePtr Q)
{
    if(Q->head >= Q->tail)
        return OK;
    return ERROR;
}
Status GetHead(QueuePtr Q, SElemType *e)
{
    if(!QueueEmpty(Q))
    {
        *e = Q->data[Q->head];
        return OK;
    }
    return ERROR;
}
size_t QueueLength(QueuePtr Q)
{
    if(!QueueEmpty(Q))
    {
        return (Q->tail - Q->head + MAXSIZE) % MAXSIZE;
    }
    return 0;
}
void PrintQueue(QueuePtr Q)
{
    if(QueueEmpty(Q))
        return;
    size_t length = QueueLength(Q);
    cout<<"------------QueuList------------"<<endl;
    for(int i = Q->head; i < Q->tail; ++i)
    {
        cout<<Q->data[i]<<endl;
    }
    cout<<"-------------QueueListEnd----------"<<endl;
}

void test()
{
    t_Queue t;
    InitQueue(&t);
    EnQueue(&t,1);
    EnQueue(&t,2);
    ClearQueue(&t);
    PrintQueue(&t);
    EnQueue(&t,3);
    EnQueue(&t,4);
    PrintQueue(&t);
    SElemType a = 0;
    DeQueue(&t,&a);
    cout<<" a = "<<a<<endl;
    EnQueue(&t,5);
    GetHead(&t,&a);
    cout<<"GetHead = "<<a<<endl;
    PrintQueue(&t);
}

int main()
{
    test();
    return 0;
}

