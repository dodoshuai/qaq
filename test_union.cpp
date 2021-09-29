#include <iostream>
using namespace std;
typedef char ElemType;
struct GameZone_t
{
    union
    {
        int id;
        struct
        {
            ElemType zone;
            ElemType game;
        };
    };
    GameZone_t()
    {
        this->game = 0;
        this->zone = 0;
    }
    GameZone_t(const GameZone_t &gamezone)
    {
        this->id = gamezone.id;
    }
};
int main()
{
    GameZone_t a;
    cout<<" id:" << a.id <<endl;
    cout<<" zone:"<<(int)a.zone<<" game:"<<(int)a.game<<endl;
    a.zone = 7;
    a.game = 15;
    cout<<" id:" << a.id <<endl;
    cout<<" zone:"<<(int)a.zone<<" game:"<<(int)a.game<<endl;
    a.id = 1807;
    cout<<" id:" << a.id <<endl;
    cout<<" zone:"<<(int)a.zone<<" game:"<<(int)a.game<<endl;
    return 0;
}

