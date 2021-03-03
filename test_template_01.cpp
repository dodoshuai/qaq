#include <iostream>
#include <string>
using std::string;
template <typename T> inline T min(const T&, const T&);

template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}
//int compare(const string &v1, const string &v2)
//{
//    if (v1 < v2) return -1;
//    if (v2 < v1) return 1;
//    return 0;
//}
//int compare(const double &v1, const double &v2)
//{
//    if (v1 < v2) return -1;
//    if (v2 < v1) return 1;
//    return 0;
//}
void test1()
{
    string a1("abc");
    string b1("cba");
    std::cout<<"abc < cba  :: "<<compare(a1,b1)<<std::endl;
}
void test2()
{
    double a1=1.0;
    double b1=0.9;
    std::cout<<"abc < cba  :: "<<compare(a1,b1)<<std::endl;
}
int main()
{
    test1();
    std::cout<<"---------------"<<std::endl;
    test2();
    return 0;
}

