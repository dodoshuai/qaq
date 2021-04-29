#include <iostream>
#include <string>
using namespace std;

class base{
public:
    base(){
        cout<<"base"<<endl;
        print();
    }
    virtual void print()
    {
        cout<<"print base"<<endl;
    }
    virtual ~base()
    {
        print();
    }
private:
};
class derived:public base{
public:
    derived(){
        cout<<"derived"<<endl;
        print();
    }
   // void print()
   // {
   //     cout<<"print derived"<<endl;
   // }
    virtual ~derived(){
        print();
    }
private:
};
void test(){
    cout<<"----------------"<<endl;
    base q1;
    cout<<"----------------"<<endl;
    derived q2;
    cout<<"----------------"<<endl;
}
int main()
{
    test();
    return 0;
}

