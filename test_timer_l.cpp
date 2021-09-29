#include <iostream>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

#define TIME_WHEEL_SIZE 8

typedef void (*func)(int data);
typedef struct time_node* listNode;
typedef int Node_Size;
typedef int Elemtype;
struct time_node{
    listNode next;
    Node_Size rotation;
    func proc;
    Elemtype data;
};

struct timer_wheel{
    listNode slot[TIME_WHEEL_SIZE];
    int current;
};

struct timer_wheel timer = {{0}, 0};

void tick(int signo)
{
    listNode *cur = &timer.slot[timer.current];
    while(*cur)
    {
        listNode curr = *cur;
        //这里可以使用线程池定时任务重启一个线程
        if(curr->rotation > 0)
        {
            curr->rotation--;
            cur = &curr->next;
        }
        else
        {
            curr->proc(curr->data);
            *cur = curr->next;
            free(curr);
        }
    }

    timer.current = (timer.current + 1) % TIME_WHEEL_SIZE;
    alarm(1);
}

void add_timer(int len, func action)
{
    int pos = (len + timer.current) % TIME_WHEEL_SIZE;
    listNode node =(listNode)malloc(sizeof(struct time_node));
    
    //插入对应轮数的链表头部
    node->next = timer.slot[pos];
    timer.slot[pos] = node;
    node->rotation = len / TIME_WHEEL_SIZE;
    node->data = 0;
    node->proc = action;
}


//test case1:1s循环定时器
int g_sec = 0;
void do_time1(int data)
{
    printf("timer %s, %d\n", __FUNCTION__, g_sec++);
    add_timer(1, do_time1);
}

// test case2:2s单次定时器
void do_time2(int data)
{
    printf("timer %s, %d\n", __FUNCTION__, g_sec);
}

// test case3: 9s循环定时器
void do_time9(int data)
{
    printf("timer %s, %d\n", __FUNCTION__, g_sec);
    add_timer(9, do_time9);
}

void test()
{
    signal(SIGALRM, tick);
    alarm(1);

    add_timer(1,do_time1);
    add_timer(2,do_time2);
    add_timer(9,do_time9);

    while(1) pause();
}

int main()
{
    test();
    return 0;
}
