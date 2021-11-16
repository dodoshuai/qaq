#include <iostream>
using namespace std;

//普通变量, 改变存储区域和生命周期，使变量存储在静态区
static int a1 = 10; //有初始值就用初始值初始化，没有就用默认值初始化
//静态函数,限定函数作用范围，只能在定义该函数的文件内使用
static int func_1()
{
    cout <<"static function "<< endl;
    return 0;
}

class A{
public:
    A():p_b_(0){}
    A(int a = 0):p_b_(a){}
    static void func_2()    //不能访问非静态成员变量，可以在生成对象之前使用
    {
        cout<< "--------------------------"<<endl;
        cout<< "func_1 static :" << s_a_ <<endl;
        cout<< "static a1:"<< a1 <<endl;
        func_1();
        cout<< "--------------------------"<<endl;
    }
    void func_3()
    {
        cout <<" static: " << s_a_<<endl;
        cout <<" common: " << p_b_ <<endl;
    }
    void set_static_a(int a)
    {
        s_a_ = a;
    }
private:
    static int s_a_;    //静态成员变量可以在生成对象之前进行调用(访问控制符限制),请配合静态成员函数使用效果更佳
    int p_b_;
};
int A::s_a_ = 2;    // 类中的静态成员变量必须手动初始化

void test()
{
    cout<< " a1 = " << a1 << endl;
    func_1();
    A::func_2();
    A s1(1);
    s1.func_3();
    s1.set_static_a(3);
    A::func_2();
    s1.func_3();
}
int main()
{
    test();
    return 0;
}

