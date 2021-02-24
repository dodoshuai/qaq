#include <iostream>
#include <string>
using namespace std;

class SmallInt{
public:
    SmallInt(int i=0):val(i)
    {
        if(i < 0 || i > 255)
            cout<< "ERROR!"<<endl;
    }
    operator int() const 
    {
        return val;
    }

private:
    int val;
};
int main()
{
    SmallInt si(3);
    cout<< "si = " << si+3.14159 <<endl;

    double dval= 2;
    cout<< "si >= dval";
    if(si >= dval)
        cout<<"\tyes!"<<endl;
    else
        cout<<"\tno!"<<endl;

    if(si)
        cout<<"\tyes!"<<endl;
    else
        cout<<"\tno!"<<endl;

    cout<<"si = "<<si<<endl;

    int ival;
    SmallInt s = 3.541;
    ival = static_cast<int>(s) + 3;
    cout<<"ival = "<< ival<<"\ts = "<<s<<endl;
//    std::cout << "Hello world" << std::endl;
    return 0;
}

