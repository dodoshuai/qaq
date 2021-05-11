#include <iostream>
#include <string>
#include <vector>
using namespace std;

//class String{
//    public:
//        String
//        int str[100];
//};
/* 通过计算返回子串T的next数组。*/
void get_next(string  T, int *next)
{
    int i,j;
    i = 1;
    j = 0;
    next[0] = 0;
    while (i < T.size())
    {
        if(j == 0 || T[i] == T[j])
        {
            if(T[i] == T[j])
                ++j;
            ++i;
            if(T[i] != T[j])
                next[i] = j;
            else
                next[i] = next[j];
        }
        else
            j = next[j];
    }
}
/* 返回子串T再主串S中第pos个字符之后的位置。若不存在，则函数返回值为0。“
 * T非空，l<=pos<=StrLength(s).*/
int Index_KMP(string s, string T, int pos)
{
    int  i = pos;
    int j = 0;
    int next[255]={0};
    get_next(T,next);
    for(int i=0;i<T.size();++i)
        cout<<next[i]<<" ";
    cout<<endl;
    cout<<"-------get_next()-----------"<<endl;
    while(i< s.size() && j<T.size())
    {
        if (j == 0 || s[i] == T[j])
        {
            if(s[i]==T[j])
                ++j;
            ++i; 
            cout<<"j = " <<j<<"  i = "<< i<<endl;
        }
        else if(j!=next[j])
            j=next[j];
    }
            cout<<"ending --j = " <<j<<"  i = "<< i<<endl;

    if(j >= T.size())
        return i-T.size();
    else
        return 0;
}

void find_next(vector<int>& nums,vector<int>& res)
{
    for(auto x : nums)
        cout<<x<<" ";
    cout<<endl;
    int i=0;
    int j=1;
    for(;j<nums.size();)
    {
        cout<<"i = "<<i<<" j = "<<j<<endl;
        if( i==0 || nums[i]==nums[j])//如果前后缀相等则后缀等于前缀下标
        {
            if(nums[i] == nums[j])
                i++;
            j++;
            if(nums[i] != nums[j])
                res[j] = res[i];
            else
                res[j]=i;
            cout<<i<<" "<<res[i]<<" -- "<<j<<" "<<res[j]<<endl;
        }
        else
        {
            i=res[i];
        }
    }
}


void test()
{
    //string x("ababaaaba");
    string x("aaaaaaaabs");
    string y("aaaaaab");
    cout<<x<<endl;
    cout<<y<<endl;
    int *next = new int[x.size()];
    //get_next(x,next);
    int pos = Index_KMP(x,y,0);
    cout<<"--------"<<pos<<"-----------"<<endl;
    string z = x.substr(pos,y.size());
    cout<<x<<endl;
    cout<<z<<endl;
//    for(int i=0;i<x.size();++i)
//    {
//        cout<<next[i];
//    }
//    cout<<endl;
}
void test02()
{
    vector<int> a{1,2,3,4,1,2,3,1,2};
    //vector<int> a{1,2,1,1,2,4,1,2,3};
    vector<int> b(a.size(),0);
    find_next(a,b);
    int i=0;
    for(auto i:b)
        cout<< i<<" ";
    cout<<endl;
    
}
int main()
{
    test();
    //test02();
        return 0;
}

