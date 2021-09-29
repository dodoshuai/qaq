#include <iostream>

struct qaq{
    int a=0;
    int b=0;
    int operator()(){ return a+b;}
    void print(){std::cout<<"a="<<a<<" b="<<b<<std::endl;}
};

void test()
{
    qaq t1[2];
    t1[0]=1;

}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

