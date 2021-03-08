#include <iostream>
using namespace std;

template <typename T>
int compare(const T& v1, const T& v2)
{
    cout<<"v1&v2-type :"<<typeid(v1).name()<<endl;
    if(v1 < v2) return -1;
    if(v2 < v1) return 1;
    return 0;
}
template <typename A, typename B>
int compare(const A& v1, const B& v2)
{
    cout<<"v1-type:"<<typeid(v1).name()<<endl;
    cout<<"v2-type:"<<typeid(v2).name()<<endl;
    if( v1 < v2 ) return -1;
    if(v2 < v1) return 1;
    return 0;
}
void test1()
{
    compare(1000,1024);
    short si;
    compare(si, 1024);
}
void test2()
{
    short s1,s2;
    int i1,i2;
    compare(i1,i2);
    compare(s1,s2);
}
int main()
{
    test1();
    cout<<"----------------"<<endl;
    test2();
    return 0;
}

