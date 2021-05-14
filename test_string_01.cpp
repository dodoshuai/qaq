#include <iostream>
#include <string>
using namespace std;

bool readStr(const string& s1,const string& s2)
{
    if(s1 == s2)
        return true;
    if(s1>s2)
    {
        cout<<"s1"<<endl;
        return true;
    }
    else
    {
        cout<<"s2"<<endl;
        return true;
    }
    if(s1.size() != s2.size())
    {
                
    }
}
int main()
{
    string s("Hiya!");
    string::iterator iter = s.begin();
    while(iter != s.end())
        cout << *iter++ << flush;
    cout<<endl;

    string numerics("0123456789");
    string name("r2d2");
    string::size_type pos = name.find_first_of(numerics);
    cout<<"found number at index: " << pos << " element is " << name[pos] << endl;
    
    pos = 0;
    while((pos = name.find_first_of(numerics, pos)) != string::npos)
    {
        cout<<"found number at index: " << pos << " element is " << name[pos] << endl;
        ++pos;
    }
    return 0;
}

