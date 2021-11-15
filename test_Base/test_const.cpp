#include <iostream>

using namespace std;

class A{
public:
    A(): a(0){}
    A(int x): a(x){}    //初始化列表
    int get_a(){return a;}  //普通成员函数
    int get_a() const {return a;}   //常成员函数，不得修改类中任何成员函数的值（实质为this 被const修饰）                                                                                                                                   
private:                             
    const int a;    // 可以使用初始化列表或者类内初始化
    const int b = 2; // 放在花括号里，或者放在等号右边，记住不能使用圆括号
};                                   

void function()
{
    //对象
    A a1;                   // 普通对象，可以调用全部成员函数
    const A a2;             // 常对象，只能调用常量成员函数
    const A* p_a = &a2;     // 指针变量，指向常对象 const （先左后右）辨别const修饰对象
    const A& r_a = a2;      // 指向常对象的引用
    //指针
    char greeting[] = "Hello,world!";   //普通字符数组
    char* p1 = greeting;                //指针变量，指向字符数组变量
    const char* p2 = greeting;          //指针变量，指向字符数组常量
    char* const p3 = greeting;          //常量的指针，指向字符数组变量
    char const* p4 = greeting;          //同上
    const char * const p5 = greeting;   //常量的指针，指向字符数组常量
}
//函数
void func_1(int var);               //参数可变
void func_2(const int var);         //传递过来的参数在函数内部不可变
void func_3(const int* p_var);      //参数指针所指内容为常量
void func_4(int* const p_var);      //参数指针为常量
void func_5(const int& r_var);      //引用参数在函数内为常量
//返回值
const int func_6();         //返回一个常数
const int* func_7();        //返回一个指针变量，指向常量
int* const func_8();        //返回一个常量指针，指向变量

int main()                           
{                                    
    std::cout<<"嘿嘿"<<std::endl;
    return 0;                        
}                                    
