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
int main()
{
    test();
    //std::cout << "Hello world" << std::endl;
    return 0;
}

