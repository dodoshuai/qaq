#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    const char *filename = "example.txt";
    long l,m;
    ifstream file(filename, ios::in|ios::binary);
    l = file.tellg();
    file.seekg(0, ios::end);
    m = file.tellg();
    file.close();
    cout<<"size of "<< filename;
    cout<<" is "<< (m-1) <<"bytes.\n";
    return 0;
}

