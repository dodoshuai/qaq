#include <iostream>
#include <vector>
#include <string>
using namespace std;
using std::string;
class student{
public:
    student(string _ID="",unsigned int _age=0):ID(_ID),age(_age)
    {
    }
    bool qaq(student &s) const
    {
        return this->ID==s.ID;
    }
    void show()
    {
        std::cout<<ID<<" "<<age<<std::endl;
    }
private:
    string ID;
    unsigned int age;
};
int main()
{
    vector<vector<string>> lines;
    student a("abc",12);
    student b("cba",13);
    if(a.qaq(b))
    a.show();
    std::cout << "Hello world" << std::endl;
    return 0;
}

