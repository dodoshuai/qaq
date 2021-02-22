#include <iostream>
#include <string.h>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::cin;
int main()
{
    size_t size=5;
    const char *str="a very long literal";
    //cin>>str;
    //scanf("%s",str);
    //printf("%s",str);
    cout<<str<<endl;
    cout<<strlen(str)<<endl;
//    std::cout << "Hello world" << std::endl;
    for(const char *it=str;it<str+size;it++)
        cout<<it[0];
    cout<<endl;
    char *str2=new char[size+5];
    strcpy(str2,str);
    cout<<str2<<endl;
    cout<<strlen(str2)<<endl;
    delete [] str2;
    return 0;
}

