#include <iostream>
#include <vector>
using namespace std;
int arr[3]={1,2,3};
vector<int> ret;
void print()
{
    for(int i=0;i<ret.size();++i)
    {
        cout<<" "<<ret[i];
    }
    cout<<endl;
}
void powerSet(int i, int n)
{
    if(i>n)
        print();
    else
    {
        ret.push_back(arr[i-1]);
        powerSet(i+1,n);
        ret.pop_back();
        powerSet(i+1,n);
    }
}
class hsf
{
public:
    hsf(int a=0,int b=0):l(a),w(b)
    {
        if(l&&w)
        {
            arr.resize(l);
                for(int i=0;i<arr.size();++i)
                    arr[i].resize(w);
        }
        for(int i=0;i<arr.size();++i)
        {
            for(int j=0;j<arr[i].size();++j)
                arr[i][j]=0;
        }
    }
    ~hsf(){}
    static void print_count()
    {
        cout<<hsf::count<<endl;
    }
    void print()
    {
        cout<<">>>>>>>>--------"<<endl;
        for(int i=0;i<arr.size();++i)
        {
            for(int j=0;j<arr[i].size();++j)
            {
                cout<<" "<<arr[i][j];
            }
            cout<<endl;
        }
        cout<<"--------<<<<<<<<<"<<endl;
    }
    bool checkTrial(int a,int b)
    {
        for(int i=0;i<a;++i)
            if(arr[i][b]!=0)
                return false;
        for(int j=0;j<b;++j)
            if(arr[a][j]!=0)
                return false;
        int x1 = b-a;
        int x2 = b+a;
        //cout<<"a="<<a<<" b="<<b<<endl;
        //cout<<"x1="<<x1<<" x2="<<x2<<endl;
        for(int j=0;j<arr[0].size();++j)
        {
            int i = 0;
            if(j==b)
            {
                continue;
            }
            else if(j<b)
            {
                i=j-x1;
            }
            else if(j>b)
            {
                i=x2-j;
            }
            if(i>=0&&arr[i][j]!=0)
                return false;
        }
        return true;
    }
    void Trial(int i,int n)
    {
        if( i > n)
        {
            print();
            count++;
        }
        else for(int j = 0;j<=n; ++j)
        {
            arr[i][j]=1;
            if(checkTrial(i,j))
            {
               // print();
                Trial(i+1,n);

            }
            arr[i][j]=0;
        }
    }
private:
    vector<vector<int>> arr;
    int l;
    int w;
    static int count;
};
int hsf::count=0;
int main()
{
    //powerSet(1,3);
    hsf q1(8,8);
    q1.Trial(0,7);
    q1.print_count();
    return 0;
}

