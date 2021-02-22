#include<iostream>
#include<vector>
int sort(vector<int>& arr,std::function<bool(vector<int>&)> less=[&](int &a,int& b)->bool{return a<b;})
{
    int h = 1;
    while(h<arr.size()/3) h=h*3+1;

    while(h>=1)
    {
        for(int i=h;i<arr.size();i++)
        {
            for(j=i;j>=h&&arr[j]<arr[j-h];j-=h)
                swap(arr[j],arr[j-h]);
        }
        h=h/3;
    }
    return 0;
}
