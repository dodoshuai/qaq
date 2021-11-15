#include <iostream>
using namespace std;

class A{
public:
    A(){
        cout<< " A con "<<endl;
    }
    virtual ~A();
};
A::~A()
{
        cout<<" ~A con "<<endl;
}
class B:public A
{
public:
    B(){
        cout<< " B con "<<endl;
    }
    ~B() override{
        cout<<" ~B con "<<endl;
    }
};

void test()
{
    A a;
    B b;
}
int main()
{
    test();
    return 0;
}

