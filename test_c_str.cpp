#include <iostream>
#include <string>
#include <string.h>
using namespace std;
void test()
{
    string a="123";
    //char* b = a.c_str();
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<a.c_str()<<endl;
    char c[20];
    strcpy(c,a.c_str());
    cout<<"a = "<<a<<endl;
    cout<<"c = "<<c<<endl;
    int num = atoi(a.c_str());
    cout<< "num = "<< num<<endl;
    string d;
    int num2 = atoi(d.c_str());
    cout<<"num2 = "<< num2<<endl;
}
int main()
{
    test();
    return 0;
}

