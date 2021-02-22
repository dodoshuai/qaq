#include <iostream>
#include <map>
using namespace std;
 
int main()
{
    map<string, int> m1, m2;
    m1["hello"] = 1;
    m1["world"] = 20;
    map<string,int> m3(m1);
    m2 = m1;
    cout << m2["world"] << endl;
    cout << m3["world"] << endl;
    return 0;

}
