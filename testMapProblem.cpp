#include <iostream>
#include <map>
#include <set>
using std::cout;
using std::endl;

std::map<int,std::set<int>> lastSort;
std::map<int,std::set<int>> nowSort;

void print_map(std::map<int,std::set<int>> & sortMap)
{
    cout<<"-------------------map Start------------------"<<endl;
    for(auto mIter = sortMap.begin(); mIter != sortMap.end(); ++mIter)
    {
        cout<<"-------------------sort Start------------------"<<endl;
        for(auto sIter = mIter->second.begin(); sIter!= mIter->second.end(); ++sIter)
        {
            cout<<"st :" << *sIter <<endl;
        }
        cout<<"-------------------sort End--------------------"<<endl;
    }
    cout<<"-------------------map End--------------------"<<endl;
}
void test()
{
    std::set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(0);
    s.insert(5);
    lastSort[1] = s;
    lastSort[2] = s;
    lastSort[3] = s;
    print_map(lastSort);
    nowSort = lastSort;
    print_map(nowSort);
}
int main()
{
    test();
    return 0;
}

