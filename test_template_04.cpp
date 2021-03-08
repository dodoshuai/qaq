#include <iostream>
#include <string>
using namespace std;

template <typename T> 
T fobj(T a,T b)
{
    cout<<"~& ~&"<<endl;
    cout<<"a = "<< a <<" address : "<< &a <<endl;
    cout<<"b = "<< b <<" address : "<< &b <<endl;
    return a;
}
template <typename T> 
T fref(const T& a, const T& b)
{
    cout<<"&&&&&&"<<endl;
    cout<<"a = "<< a <<" address : "<< &a <<endl;
    cout<<"b = "<< b <<" address : "<< &b <<endl;
    return a;
}
void test1()
{
    string s1("a value");
    const string s2("another value");
    cout<<"s1 = "<<s1<<" address : "<< &s1 <<endl;
    cout<<"s2 = "<< s2 <<" address : "<< &s2 <<endl;
    fobj(s1,s2);
    fref(s1,s2);
    int a[10], b[42];
    cout<<"a = "<< a <<" address : "<< &a <<endl;
    cout<<"b = "<< b <<" address : "<< &b <<endl;
    fobj(a,b);
    //fref(a,b);
}
int main()
{
    test1();
    return 0;
}

