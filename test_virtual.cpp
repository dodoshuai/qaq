#include <iostream>
#include <string>
using namespace std;

class base{
public:
    virtual void print(string str="aaa") {cout<<"base: "<<str<<endl;}
private:
    string basename;
};
class derived:public base{
public:
    virtual void print(string str="bbb") {base::print(); cout<<"derived: "<<str<<endl;}
private:
    int mem;
};
void test()
{
    base a;
    derived b;
    cout<<"---------------" << 1 << "--------------"<<endl;
    a.print();
    b.print();
    cout<<"---------------" << 2 << "--------------"<<endl;
    base *p1=&a;
    base *p2=&b;
    p1->print();
    p2->print();
    //derived *p3 = &a;
    derived *p4 = &b;
    //p3->print();
    p4->print();
    base &q1=a;
    base &q2=b;
    //derived &q3=a;
    derived &q4=b;
    cout<<"---------------" << 3 << "--------------"<<endl;
    q1.print();
    q2.print();
    //q3.print();
    q4.print();
}
class A{
public:
    A()
    {
        fun();
        this->fun();
    }
    virtual ~A()
    {
        cout<<"print A"<<endl;   
    }
    void fun(string str="aaa") {cout<<"A: "<<str<<endl;}
};
class B : public A{
    public:
        B(){
            fun();
            this->fun();
        }
        ~B()
        {
            cout<<"print B"<<endl;
        }
    void fun(string str="bbb") {cout<<"B: "<<str<<endl;}
};
void test2()
{
    A* a1 = new B();
    B* b1 = new B();
    delete a1;
    cout<<"------------------"<<endl;
    delete b1;
}
void test3()
{
    B b;
    cout<<"--------------"<<endl;
    b.fun();
}
int main()
{
    //test();
    //test2();
    test3();
    //std::cout << "Hello world" << std::endl;
    return 0;
}

