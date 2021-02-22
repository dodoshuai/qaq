#include <iostream>

int main()
{
    auto x = 2;
    auto y = 4;
    decltype(x+y) z;
    z = x+y;
    std::cout<<z<<std::endl;
    std::cout << "Hello world" << std::endl;
    if (std::is_same<decltype(x), int>::value)
            std::cout << "type x == int" << std::endl;
    if (std::is_same<decltype(x), float>::value)
            std::cout << "type x == float" << std::endl;
    if (std::is_same<decltype(x), decltype(z)>::value)
            std::cout << "type z == type x" << std::endl;
    return 0;
}

