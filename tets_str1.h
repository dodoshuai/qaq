#pragma once

class tets_str1
{
public:
    tets_str1() {}
    ~tets_str1() {}
    static int getCount() {return count;}
private:
    class Rep;
    Rep* p;
    static int count;
};

