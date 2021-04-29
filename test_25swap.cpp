#include <iostream>
class WidgetImpl{
public:
    WidgetImpl(int data):a(data){}
    void print()
    {
        std::cout<<"show : "<<a<<std::endl;
    }
private:
    int a;
};
class Widget{
public:
    Widget(const Widget& rhs);
    Widget& operator=(const Widget& rhs)
    {
        Widget temp(rhs);
        using std::swap;
        swap(pImpl,temp.pImpl);
    }
    void swap(Widget& other)
    {
        using std::swap;
        swap(pImpl,other.pImpl);
    }
private:
    WidgetImpl* pImpl;
};
//namespace std {
// template<>
//     void swap<Widget>(Widget& a, Widget& b)
//     {
//         swap(a.pImpl, b.pImpl);
//     }
//}
namespace std {
    template<>
        void swap<Widget>(Widget& a, Widget& b)
        {
            a.swap(b);
        }
}

int main()
{
    return 0;
}

