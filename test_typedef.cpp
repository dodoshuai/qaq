#include <iostream>
#include <string>
class B{
    public:
        std::string s;
        int size;
        void show()
        {
            std::cout<<" s = " <<s<<std::endl;
            std::cout<<" size = "<<size<<std::endl;
        }
};
template<typename T>
class A{
    typedef typename T::value_type value_type;
    public:
    //void operator()(std::string s)
    //{
    //    std::cout<< s <<std::endl;
    //}
    void operator()(value_type size)
    {
        size_ = size;
        std::cout<< (int)size_ <<std::endl;
    }
    private:
    value_type size_;
};
void test()
{
    A<std::string> a;
    //a("hello,world!");
    a(111);
}
void test01()
{
    A<B> b;
    b(111);
}
int main()
{
    test01();
    return 0;
}

