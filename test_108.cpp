#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main(){
    ofstream examplefile;
    examplefile.open("example.txt");
    if(examplefile.is_open())
    {
        examplefile << "This is a line.\n";
        examplefile << "This is another line.\n";
        examplefile << "This is q line.\n";
        examplefile.close();
    }
    return 0;
}
