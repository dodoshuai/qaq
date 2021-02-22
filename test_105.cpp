#include <iostream>
#include <stdexcept>
using namespace std;
int main()
{
    int item1;
    while(std::cin>>item1)
    {
        try{
            if(0 == item1)
                throw runtime_error("hello world");
        }catch(runtime_error err)
        {
            cout<<err.what()<<"\n Try Again? Enter y or n"<<endl;
            char c;
            cin>>c;
            if(cin && c == 'n')
                break;
        }
    }
//    std::cout << "Hello world" << std::endl;
    return 0;
}

