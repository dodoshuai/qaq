#include <iostream>
#include <bitset>
#include <string>
using namespace std;
void test1()
{
    string str("11111111000000011001101");
    bitset<32> bitvec5(str,5,4);
    bitset<32> bitvec6(str,str.size()-4);
    cout<<str<<endl;
    for(int i=0; i<bitvec5.size();++i)
        cout<<bitvec5[i]<<" ";
    cout<<endl;
    for(int i=0; i<bitvec6.size();++i)
        cout<<bitvec6[i]<<" ";
    cout<<endl;

    cout<<"------------------"<<endl;
    bool is_set = bitvec5.any();
    bool is_not_set = bitvec5.none();
    size_t bits_set = bitvec5.count();
    cout<<"is_set: "<<is_set << " is_not_set: "<<is_not_set<<" bits_set: "<<bits_set<<endl;
    cout<<"---------------"<<endl;
    cout<<"bitvec5: "<<bitvec5<<endl;
}
int main()
{
    test1();
    return 0;
}

