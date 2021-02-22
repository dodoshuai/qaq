#include <iostream>
#include <memory>
void foo(std::shared_ptr<int> i)
{
        (*i)++;
        std::cout<<i.use_count()<<std::endl;       
}
int main()
{
    //auto pointer = new int(10); // illegal, no direct assignment
    // Constructed a std::shared_ptr
    auto pointer = std::make_shared<int>(10);
    std::cout<<pointer.use_count()<<std::endl;       
    foo(pointer);
    std::cout << *pointer << std::endl; // 11
    std::cout<<pointer.use_count()<<std::endl;       
    // The shared_ptr will be destructed before leaving the scope
    return 0;

}
