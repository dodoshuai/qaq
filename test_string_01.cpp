#include <iostream>
#include <string>
using namespace std;

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

