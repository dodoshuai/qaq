#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void print()
{
    string ifile("test_pri.txt");
    ifstream infile(ifile.c_str());
    string ofile("test_pri2.txt");
    ofstream outfile(ofile.c_str());
    infile.open("in");
    outfile.open("out");
    if(!infile)
    {
        cerr<< "error: unable to open input file: "<< ifile <<endl;
        return;
    }
    if(!outfile)
    {
        cerr<< "error: unable to open input file: "<< ifile <<endl;
        return;
    }
}
void process(string& s)
{
    ofstream output;
    string ofile("test_pri2.txt");
    output.open(ofile, ofstream::out | ofstream::app);
    if(!output)
    {
        cerr<<"error: unable to open input file: "<< ofile <<endl;
        return;
    }
    if(!(output << s))
    {
        cerr<<"error: unable to open input file: "<< ofile <<endl;
    }
    output << endl;
    output.close();
    output.clear();
}
void read(string& s)
{
    ifstream input;
    input.open(s.c_str());
    if(!input)
    {
        cerr<<"error: unable to open input file: "<< s <<endl;
        return;
    }
    string line;
    while(input >> line)
    {
        process(line);
    }
    input.close();
    input.clear();
}

int main()
{
//    print();
    string ifile("test_pri.txt");
    read(ifile);
    return 0;
}

