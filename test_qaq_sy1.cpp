#include <iostream>
#include <string>
#include <vector>
#include "timer.h"
using namespace std;

typedef int PointTimeType;
typedef int PosType;
class Record{
    public:
        Record(){}
        ~Record(){}
        void addTimePiont(PointTimeType t)
        {timeVec.push_back(t);}
        PointTimeType getTimePoint(PosType i)
        {
            if(0<i && i < timeVec.size())
                return timeVec[i];
            return (PointTimeType)0;
        }
    private:
        vector<PointTimeType> timeVec;
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

