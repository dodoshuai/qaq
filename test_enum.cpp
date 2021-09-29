#include <iostream>
using namespace std;

enum tt {a=0,b,c};
enum ts {e,w,q};
void h()
{
    // 枚举类型在实际应用中，视为一个单独类型，不可以由int类型直接初始化
    //tt t = 2;
    
    tt t = tt(2);
    int i = c;
}

void g(enum tt* pc, enum ts* pv)
{
    // 不同的枚举类型视为不同的类型，不能直接赋值
    //pc = pv;
}

tt operator++(tt s)
{
    switch(s)
    {
    case a: return b;
    case b: return c;
    case c: return a;
    }
    return tt(0);
}

void f(tt)
{
    cout<< "tt"<<endl;
}
void f(ts)
{
    cout<< "ts"<<endl;
}

namespace TestSpace {
enum class Color {  //限定作用域的枚举类型
    red = 0,
    green,
    blue,
};
enum  Color_sec {   //非限定作用域的枚举类型
    black = 0,
    ore,
    yellow,
};
};
void test2()
{
    using namespace TestSpace;
    for(int i = 0; i <= static_cast<int>(Color::blue); ++i)
    {
        std::cout<< i << std::endl;
    }
    std::cout<< "--------"<< std::endl;
    Color color = Color::green;
    if(1 < static_cast<int>(color) < 2)
    {
        std::cout << static_cast<int>(color) << std::endl;
    }
    return;
}

void test3()
{
    using namespace TestSpace;
    for(int i = 0; i <= Color_sec::yellow; ++i)
    {
        std::cout<< i << std::endl;
    }
    std::cout<< "--------"<< std::endl;
    Color_sec color_sec = Color_sec::yellow;
    if(1 < color_sec)
    {
        std::cout << color_sec << std::endl;
    }
    return;
}

void test()
{
    tt s = tt(1);
    cout<<"tt = " << s <<endl;
    tt s1=++s;
    cout<<"tt = " << s1 <<endl;
    tt s2=++s1;
    cout<<"tt = " << s2 <<endl;
    tt s3=++s2;
    cout<<"tt = " << s3 <<endl;
}
int main()
{
    //test();
    test2();
    std::cout<< "-----------test3---------------"<<std::endl;
    test3();
    return 0;
}

