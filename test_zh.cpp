#include <iostream>
#include <string>
using namespace std;

class SmallInt{
public:
    SmallInt(int i=0):val(i)
    {
        if(i < 0 || i > 255)
            cout<< "ERROR!"<<endl;
    }
    operator int() const 
    {
        return val;
    }
    operator double() const
    {
        return val;
    }
    //int operator+(const int a)
    //{
    //    return val + a;
    //}
//    friend SmallInt operator+(const SmallInt& a, const SmallInt& b);
private:
    int val;
};

class Integral{
public:
    Integral(int i=0):val(i)
    {
        if(i < 0 || i > 255)
            cout<< "ERROR!"<<endl;
    }
    operator int() const 
    {
        return val;
    }
    operator double() const
    {
        return val;
    }

private:
    int val;
};



void compute(int)
{
    cout<<"int"<<endl;
}
void compute(double)
{
    cout<<"double"<<endl;
}
void compute(long double)
{
    cout<<"long double"<<endl;
}
/*
 * 测试定义单个类类型转换函数的注意事项
 */
void test1()
{
    //SmallInt si(3);
    //cout<< "si = " << si+3.14159 <<endl;

    //double dval= 2;
    //cout<< "si >= dval";
    //if(si >= dval)
    //    cout<<"\tyes!"<<endl;
    //else
    //    cout<<"\tno!"<<endl;

    //if(si)
    //    cout<<"\tyes!"<<endl;
    //else
    //    cout<<"\tno!"<<endl;

    //cout<<"si = "<<si<<endl;

    //int ival;
    //SmallInt s = 3.541;
    //ival = static_cast<int>(s) + 3;
    //cout<<"ival = "<< ival<<"\ts = "<<s<<endl;
}
/*
 *  测试定义多个类类型转换后的消除二义性方法
 *  显示强制转换消除二义性
 */
void test2()
{
    SmallInt si;
    compute(static_cast<int>(si));
    compute(static_cast<double>(si));
}

void manip(const Integral& qa)
{
    cout<<"Intergral"<<endl;
}
void manip(const SmallInt& qa)
{
    cout<<"SmallInt"<<endl;
}
/*
 *  显式构造函数调用消除二义性
 */
void test3()
{
    manip(SmallInt(10));
    manip(Integral(10));
}

//SmallInt operator+(const SmallInt& a, const SmallInt& b)
//{
//    return SmallInt(a.val + b.val);
//}
/*
 * 会有二义性
 */
void test4()
{
    SmallInt sc(5);
    SmallInt s2(4);
    int iobj = static_cast<int>(sc) + 3.1;
    cout << " iobj = "<< iobj<<endl;
    SmallInt s3 = static_cast<int>(sc) + static_cast<int>(s2);
    cout<< "s3 = "<<static_cast<int>(s3)<<endl;
    int i = static_cast<int>(s3) + 0;
    cout<< "i = " <<i<<endl;
}
int main()
{
    test4();
//    test3();
//    test2();
//    std::cout << "Hello world" << std::endl;
    return 0;
}

