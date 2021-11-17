#include <iostream>
using namespace std;
class test_time{
public:
    test_time()
    {
        start_ = clock();
    }
    ~test_time()
    {
        end_ = clock();
        show();
    }
    void show()
    {
        cout<<"start:"<<start_<<"   end:"<<end_<<"  last:"<<(end_ - start_)<<endl;
    }
private:
    clock_t start_;
    clock_t end_;
};

class A{
public:
    void func_1(){                          //在类声明中定义函数，默认为内联函数
        test_time t;
        cout<<"func_1"<<endl;
    }
    inline void func_2();                   //在类声明处添加内联标识符
    void func_4();                          //在成员函数类外定义时添加内联标识符
    void func_6();
private:

};

void A::func_2()
{
    test_time t;
    cout<<"func_2"<<endl;
}
inline void func_3()        //普通内联函数可以在声明处添加内联标识符，也可以在定义时添加内联标识符
{
    test_time t;
    cout<<"func_3"<<endl;
}
inline void A::func_4()
{
    test_time t;
    cout<<"func_4"<<endl;
}
static inline void func_5()
{
    test_time t;
    cout<<"func_5"<<endl;
}
void A::func_6(){
    test_time t;
    cout<<"no-inline func_6"<<endl;
}
void func_7()
{
    test_time t;
    cout<<"no-inline func_7"<<endl;
}
void test()
{
    A a;
    a.func_2();
    a.func_1();
    a.func_4();
    a.func_6();
    func_3();
    func_5();
    func_7();
}
int main()
{
    test();
    return 0;
}

