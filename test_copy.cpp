/*
 *为了防止复制，类必须显式声明其复制构造函数为`private`。
 *防止类的友元和成员仍可以进行复制，需要将复制构造函数只是声明但不对其定义。
 *代码中进行了上述的防止复制的处理时，用户代码中的复制尝试将在编译时标记为错误，
 *而成员函数和友元中的复制尝试将在链接时导致错误。
 *
 */
#include <iostream>
#include <string>
using std::string;
class student{
    public:
        student(int ID = 0, string str = ""):id(ID), name(str)
        {}
        void cpy()
        {
            student d(*this);
            d.print();
        }
        void print()
        {
            std::cout<<"ID: "<<id<<"\tname: "<< name << std::endl;
        }
    private:
       // student(const student& s)
       // {
       //     id = s.id;
       //     name = s.name;
       // }
        student(const student& s);
        int id;
        string name;
};
/*void test()
{
    student a(1,"aa");
    student b(a);
    a.print();
    b.print();
}
*/
void test1()
{
    student a(1,"aa");
    a.print();
    a.cpy();
}
int main()
{
    //test();
    test1();
    //std::cout << "Hello world" << std::endl;
    return 0;
}

