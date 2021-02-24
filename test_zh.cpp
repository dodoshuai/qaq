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
//    std::cout << "Hello world" << std::endl;
    return 0;
}

