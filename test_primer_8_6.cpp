#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void print()
{
    string line,word;
    while(getline(cin,line))
    {
        istringstream stream(line);
        while(stream >> word)
        {
            cout<<word<<endl;
        }
    }
}
void test2()
{
    int val1 = 512, val2 = 1024;
    ostringstream format_message;
    format_message << "val1: " << val1 << "\n" << "val2: " << val2 << "\n";
    cout<< format_message.str() <<endl;

    istringstream input_istring(format_message.str());
    string dump;
    input_istring >> dump >> val1 >> dump >> val2;
    cout << val1 << " " << val2 << endl;
}

int main()
{
    //print();
    test2();
    return 0;
}

