#include <iostream>
#include <string>
using namespace std;
class student{
    public:
        explicit student(const string &str=""):name(str), id(""), age(0)
        {}
        student(istream &is);
        void abc(student a)
        {
            cout<<"-----"<<a.name<<"-------"<<endl;
        }
    private:
            string name;
            string id;
            int age;
};
student::student(istream &is)
{
    cout<<"||||||"<<endl;
}
int main()
{
    student x1;
    string null_book = "aaa";
    x1.abc(cin);
    x1.abc(student(null_book));
    return 0;
}

