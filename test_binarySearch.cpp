#include <iostream>
#include<vector>
using namespace std;
void printFlag(vector<int>& nums,int left, int right)
{
    vector<int> tempVec(nums.size(),0);
    tempVec[left] = 1;
    tempVec[right] = 2;
    for(int i=0; i<tempVec.size(); ++i)
    {
        if(tempVec[i] == 0)
            cout<<" ";
        else
            cout<<tempVec[i];
    }
    cout<<endl;
    for(int i=0;i<nums.size();++i)
    {
        cout<<nums[i];
    }
    cout<<endl;
}
int binarySearch(vector<int>& nums, int target)
{
    int left = 0, right = nums.size()-1;
    int mid = 0;
    /*
     * 循环结束条件决定了搜索区间和具体的搜索条件
     * 1.如下条件为左闭右闭区间，搜索范围包括作为边界的本身
     * 2.由于以上区间的情况，其相应的条件处理也要改变，以确
     * 保没有重复和未覆盖到的搜索区间存在
     */
    while(left<=right)//这个结束条件决定了只有当left = right+1是循环结束
    {
        mid = left + (right-left)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
        {
            right = mid - 1;
        }
        else if(nums[mid] < target)
        {
            left = mid + 1;
        }
        printFlag(nums,left,right);
    }
    return -1;
}

int binarySearch_left_first(vector<int>& nums, int target)
{
    int left = 0, right = nums.size();
    int mid = 0;
    while(left < right)
    {
        mid = left + (right - left) / 2;
        if(nums[mid] == target)
            right = mid;
        else if(nums[mid] > target)
        {
            right = mid;
        }
        else if(nums[mid] < target)
        {
            left = mid+1;
        }
        printFlag(nums,left,right);
    }
    return left;
}

int binarySearch_right_first(vector<int>& nums, int target)
{
    int left = 0, right = nums.size();
    int mid = 0;
    while(left < right)
    {
        mid = left + (right - left) / 2;
        if(nums[mid] == target)
            left = mid+1;
        else if(nums[mid] > target)
        {
            right = mid;
        }
        else if(nums[mid] < target)
        {
            left = mid+1;
        }
        printFlag(nums,left,right);
    }
    return left-1;
}

int main()
{
    vector<int> res{1,2,3,4,5,5,5,6,7,8,9};
    cout<<"binarySearch:"<<endl<<binarySearch(res,5)<<endl;
    cout<<"binarySearch_left_first:"<<endl<<binarySearch_left_first(res,5)<<endl;
    cout<<"binarySearch_right_first:"<<endl<<binarySearch_right_first(res,5)<<endl;
    return 0;
}

