#include "BigInt_test.h"
#include<algorithm>
BigInt_test BigInt_test::absBigInt()
{
    BigInt_test ret(*this);
    ret.setflag(true);
    return ret;
}
CompareType BigInt_test::compareBigInt(BigInt_test& t)
{
    if(flag && !t.flag)
        return 1;
    if(!flag && t.flag)
        return -1;
    string left(value),right(t.value);
    left.reserve();
    right.reserve();
    if(left.size() > right.size())
        return 1;
    else if(left.size() < right.size())
        return -1;
    else
        return flag ? value.compare(t.value) : -value.compare(t.value);
}
BigInt_test& BigInt_test::operator=(BigInt_test& t)
{
    this->value = t.value;
    this->flag = t.flag;
    return *this;
}
BigInt_test BigInt_test::operator+=(BigInt_test& t)
{
    BigInt_test ret;
    if(flag == t.flag)
    {
        BigInt_test left(*this);
        BigInt_test right(t);
        reverse(left.value.begin(),left.value.end());
        reverse(right.value.begin(),right.value.end());
        int i=0;
        while(i<left.value.size() && i<right.value.size())
        {
            ret.value.push_back(left.value[i]+right.value[i]-'0');
            ++i;
        }
        if(i<left.value.size())
        {
            while(i<left.value.size())
            {
                ret.value.push_back(left.value[i]);
                ++i;
            }
        }
        else if(i<right.value.size())
        {
            while(i<right.value.size())
            {
                ret.value.push_back(right.value[i]);
                ++i;
            }
        }
        int carry=0;
        for(int j=0;j<ret.value.size();++j)
        {
            int newValue = ret.value[j] - '0' + carry;
            carry = ret.value[j]/10;
            ret.value[j] = newValue - carry*10 + '0';
        }
        if(carry)
            ret.value.push_back(carry + '0');
    }
    else
    {
        BigInt_test left = (*this).absBigInt();
        BigInt_test right = t.absBigInt();
        int compFlag = compareBigInt(t);
        if(!compFlag)
        {
            ret.setvalue("0");
            ret.setflag(true);
            return ret;
        }
        else 
        {
            if(compFlag == -1)
            {
                BigInt_test tmp(left);
                left = right;
                right = tmp;
            }
            int i=0;
            while(i<left.value.size() && i<right.value.size())
            {
                ret.value.push_back(left.value[i]-right.value[i]-'0');
                ++i;
            }
            if(i<left.value.size())
            {
                while(i<left.value.size())
                {
                    ret.value.push_back(left.value.size());
                    ++i;
                }
            }
            int carry = 0;
            for(int j=0; j < ret.value.size(); ++j)
            {
                int newValue = ret.value[j] - carry - '0';
                if(newValue < 0 ) carry = 1;
                else carry = 0;
                ret.value[j] = newValue + carry*10 + '0';
            }
            if(compFlag == 1)
                ret.setflag(left.getflag());
            else 
                ret.setflag(right.getflag());
        }
    }

    reverse(ret.value.begin(), ret.value.end());
    int i = ret.value.find_first_not_of('0');
    if(i == string::npos)
    {
        ret.setvalue("0");
        ret.setflag(true);
        return ret;
    }
    ret.setvalue(string(ret.value.begin()+ret.value.find_first_not_of("0"), ret.value.end()));
    return ret;
}

BigInt_test BigInt_test::operator-=(BigInt_test& t)
{
    BigInt_test temp(t);
    temp.setflag(!t.getflag());
    return (*this)+=temp;
}
BigInt_test BigInt_test::operator*=(BigInt_test& t)
{
    BigInt_test ret;

}
