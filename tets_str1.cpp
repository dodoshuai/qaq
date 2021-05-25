#include <iostream>
#include "tets_str1.h"
class tets_str1::Rep{ 
};
int tets_str1::count = 0;
int main()
{
    std::cout<< tets_str1::getCount()<<std::endl;
    return 0;
}
