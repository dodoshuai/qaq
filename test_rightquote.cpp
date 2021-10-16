#include <iostream>
#include <map>
#include <string>

#define MAX_TEMP 10
std::map<int, int> test01()
{
    std::map<int, int> aa;
    for(int i = 0; i < MAX_TEMP; ++i)
        aa[i]=i;
    std::cout<< "aa addr = "<< &aa <<std::endl;
    return aa;
}

void test()
{
    const auto &a1 = test01();
    auto && a2 = test01();
    std::cout<<" a1 left addr = "<< &a1 <<std::endl;
    std::cout<<" a2 right addr = " << &a2 <<std::endl;
}
void test2()
{
    int i;
    int j = 0;
    std::string str;
    std::string str1 = "hi,qaq";
    std::cout << "i = "<< i <<std::endl;
    std::cout << "j = "<< j <<std::endl;
    std::cout << "str = "<< str <<std::endl;
    std::cout << "str1 = "<< str1 <<std::endl;
}
int main()
{
//    test();
    test2();
    return 0;
}

