#include <iostream>
#include <string>
//void qaq(int a,int b)
//{
//    std::cout<<"a = "<<a<<" b = "<<b<<std::endl;
//}
void qaq(std::string &s)
{
    std::cout<<"qaq"<<s<<std::endl;
}
void qaq1(const std::string &s)
{
    std::cout<<"const qaq"<<s<<std::endl;
}
int main()
{
    std::string s="olleh";
    qaq(s);
    qaq1("hello");
//    qaq(3.0,4.0);
//    std::cout << "Hello world" << std::endl;
    return 0;
}

