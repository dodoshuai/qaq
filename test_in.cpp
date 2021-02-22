#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    istream_iterator<int> in_i(cin);
    istream_iterator<int> eof;
    vector<int> vec(in_i, eof);
//    for(auto &x:vec)
//    {
//        cout<<x<<endl;
//    }
    sort(vec.begin(), vec.end());
    ostream_iterator<int> output(cout, " ");
    copy(vec.begin(), vec.end(), output);
//    unique_copy(vec.begin(), vec.end(), output);
    return 0;
}

