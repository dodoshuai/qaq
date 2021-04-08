#include <iostream>

class window{
    public:
        virtual void display() const
        {
            std::cout<<"window"<<std::endl;
        }
    private:
};
class winds: public window
{
public:
    virtual void display() const
    {
        std::cout<<"winds"<<std::endl;
    }
private:
};
void printwindowsdisplay(window w)
{
    w.display();
}
void printwindowsdisplay_1(window& w)
{
    w.display();
}
void printwindowsdisplay_2(const window& w)
{
    w.display();
}
int main()
{
    window a;
    winds b;
    printwindowsdisplay(a);
    printwindowsdisplay_1(a);
    printwindowsdisplay_2(a);
    std::cout<< "-------------------------<<"<<std::endl;
    printwindowsdisplay(b);
    printwindowsdisplay_1(b);
    printwindowsdisplay_2(b);
    return 0;
}

