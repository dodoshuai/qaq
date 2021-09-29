#pragma once
#include "Subject.h"
#include <string>
using namespace std;
typedef string State;
class Observer
{
public:
    virtual ~Observer();
    virtual void Update(Subject* sub) = 0;
    virtual void PrintInfo() = 0;
protected:
    Observer();
    State _st;
private:

};

class ConcreteSubjectObserverA:public Observer
{
public:
    virtaul Subject* GetSubject();
    ConcreteSubjectObserverA(Subject* sub);
    virtual ~ConcreteSubjectObserverA();
}
