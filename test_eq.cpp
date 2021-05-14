#include <iostream>
//#include <string>
using namespace std;
struct A{int x,y;};
struct B{int x,y;};
void g( struct A* pa, struct B* pb)
{
  //  pa = pb;
    pa = (struct A*)pb;

    pb->x = 1;
    if (pa->x != pb ->x) cout<<"bad implementation"<<endl;
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

