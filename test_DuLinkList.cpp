#include <iostream>
using namespace std;
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef int Status;

typedef struct DulNode
{
    ElemType data;
    struct DuLNode *prior;  //直接前驱指针
    struct DuLNode *next;   //直接后驱指针
} DulNode, *DuLinkList;
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

