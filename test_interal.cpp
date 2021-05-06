#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a=012;
    int b = 0x12;
    int c = 12;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    string s("who goes with F\145rgus?\012");
    cout<<s<<endl;
    string s2(" \62\115\012");
    cout<<s2<<endl;
    string s3(" \62\t\115\n");
    cout<<s3<<endl;
    int cnt = 0;
    const int sz = cnt;
    cout<<"cnt = "<<cnt <<"sz = "<<sz<<endl;
    return 0;
}

