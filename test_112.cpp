#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s("abcdefg");
    cout<<s<<endl;
    string s2("gfedcba");
    s.assign(s2);
    cout<<s<<endl;
    s.assign(s2,4,3);
    cout<<s<<endl;
    s.assign(s2);
    cout<<s<<endl;
    //s.erase(4,s.size()-4);
    s.erase(s.begin()+4,s.end());
    cout<<s<<endl;
    s.assign(10,'q');
    cout<<s<<endl;
    s.assign(s2.begin(),s2.end());
    cout<<s<<endl;
    s.insert(s.end(),'x');
    cout<<s<<endl;
    return 0;
}

