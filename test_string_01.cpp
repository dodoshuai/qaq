#include <iostream>
#include <string>
#include <set>
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
void test01(){
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
}
void test02()
{
    set<string> a = {"aa","bb", "cc"};
    for(auto iter = a.begin(); iter != a.end(); iter++)
    {
        cout<<"iter = " << *iter << " c_str = "<<iter->c_str()<<endl;
    }
}
string clean(string s)
{
    bool flag = true;
    while(flag)
    {
        flag = false;
        for(int i=0,j=0;j<s.size(); i=j)
        {
            while(j<s.size() && s[j] == s[i])
                j++;
            if(j-i >= 3)
            {
                s = s.substr(0,i) + s.substr(j);
                flag = true;
                break;

            }

        }

    }
    return s;
}
void test03()
{
    string s1 = "WWRRRBBWW";
    cout<<"s1 = " << clean(s1) << endl;
}
int main()
{
    //test02();
    test03();
    return 0;
}

