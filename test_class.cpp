#include <iostream>
#include <string>
#include <algorithm>
#include <assert.h>
using namespace std;
class student{
public:
   student(int ID=0, string Name=""):id(ID), name(Name)
   {
       cout<<"111111111111"<<endl;
   }
   student(const student& s):id(1), name("")
   {
       student tmp(s.id,s.name);
        Swap(tmp);
       cout<<"222222222222"<<endl;
   }
   void Swap(student& s)
   {
        swap(id, s.id);
        swap(name, s.name);
   }
private:
       int id;
       string name;
};

void test1()
{
    student a(1, "aa");
    student b(a);
}
int main()
{
    //std::cout << "Hello world" << std::endl;
    test1();
    return 0;
}

