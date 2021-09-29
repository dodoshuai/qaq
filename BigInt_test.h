#pragma once
#include<iostream>
#include<string>
using std::string;
typedef int CompareType;
class BigInt_test
{
public:
    BigInt_test():value(""),flag(true) {}
    BigInt_test(string s):value(s),flag((s[0] == 1)?false:true) {}
    BigInt_test(const BigInt_test& t);
    BigInt_test& operator=(BigInt_test& t);
    friend BigInt_test operator+(BigInt_test& l,BigInt_test& r);
    friend BigInt_test operator-(BigInt_test& l,BigInt_test& r);
    friend BigInt_test operator*(BigInt_test& l,BigInt_test& r);
    friend BigInt_test operator/(BigInt_test& l,BigInt_test& r);
    friend BigInt_test operator%(BigInt_test& l,BigInt_test& r);
    BigInt_test operator+=(BigInt_test& t);
    BigInt_test operator-=(BigInt_test& t);
    BigInt_test operator*=(BigInt_test& t);
    BigInt_test operator/=(BigInt_test& t);
    ~BigInt_test() {}
    CompareType compareBigInt(BigInt_test& t);
    BigInt_test absBigInt();
    void setflag(bool t){flag=t;}
    bool getflag(){return flag;}
    void setvalue(string s){value = s;}
    string getvalue(){return value;}
private:
    string value;
    bool flag;
};

     BigInt_test operator+(BigInt_test& l,BigInt_test& r);
     BigInt_test operator-(BigInt_test& l,BigInt_test& r);
     BigInt_test operator*(BigInt_test& l,BigInt_test& r);
     BigInt_test operator/(BigInt_test& l,BigInt_test& r);
     BigInt_test operator%(BigInt_test& l,BigInt_test& r);
