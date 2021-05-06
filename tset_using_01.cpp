#include <iostream>

using std::cout;
using std::endl;
namespace blip {
    int bi = 16, bj = 15, bk = 23;
}
int bj = 0;
void manip()
{
    using namespace blip;

    ++bi;

    ++::bj;
    ++blip::bj;
    int bk = 97;
    ++bk;
    cout<<"bi:"<<bi<<endl;
    cout<<"::bj:"<<::bj<<endl;
    cout<<"blip::bj:"<<blip::bj<<endl;
    cout<<"bk:"<<bk<<endl;
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

