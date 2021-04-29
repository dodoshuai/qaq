#include <iostream>
using namespace std;

istream& read(istream &str)
{
    int ival;
    while(str>>ival, !cin.eof())
    {
        cout<<ival<<"-";
    }
    str.clear();
    return str;
}
int main()
{
    cout<<"请输入：";
    read(cin);
    return 0;
}

