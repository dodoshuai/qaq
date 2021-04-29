#include <iostream>
using namespace std;
void test1()
{
    cout << "hi!" << flush; //刷新流，不在输出中添加任何字符
    cout << "hi!" << ends;  // 在缓冲区中插入空字符null
    cout << "hi!" << endl;  // 插入新的一行
    cout << "hi!" << flush; //刷新流，不在输出中添加任何字符
    cout << "hi!" << ends;  // 在缓冲区中插入空字符null
}
void test2()
{
    cout << unitbuf << "first" << " second" << nounitbuf;
    cout << "first" << flush << " second" << flush;
}
int main()
{
    test1();
    cout<<"-------------"<<endl;
    test2();
    cout<<"-------------"<<endl;
    return 0;
}
