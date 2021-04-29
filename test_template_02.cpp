#include <iostream>
#include <ostream>
using namespace std;
template <class Type> class QueueItem {
    QueueItem(const Type & t): item(t),next(0){}
    Type item;
    QueueItem *next;
};
template <class Type> class Queue{
    public:
        Queue(): head(0), tail(0){}
        Queue(const Queue &Q): head(0), tail(0)
        {copy_elems(Q);}
        Queue& operator=(const Queue&);
        ~Queue(){destroy();}
        Type &front(){return head->item;}
        const Type &front() const {return head->item;}
        void push(const Type &);
        void pop();
        bool empty() const{return head == 0;}
       // ostream& operator<<(ostream &os, const Queue<T> &q);
    private:
        QueueItem<Type> *head;
        QueueItem<Type> *tail;
        void destroy();
        void copy_elems(const Queue&);
};
template <class Type> void Queue<Type>::destroy()
{
    while(!empty())
        pop();
}
template<class Type> void Queue<Type>::pop()
{
    QueueItem<Type>* p = head;
    head = head->next;
    delete p;
}
template<class Type>
void Queue<Type>::push(const Type &val)
{
    QueueItem<Type> *pt = new QueueItem<Type>(val);
    if(empty())
        head = tail = pt;
    else
    {
        tail -> next = pt;
        tail = pt;
    }
}
template<class Type>
void Queue<Type>::copy_elems(const Queue &orig)
{
    for(QueueItem<Type> *pt = orig.head; pt; pt = pt->next)
    {
        push(pt->item);
    }
}
template<class Type>
Queue<Type>&  Queue<Type>::operator=(const Queue &temp)
{
    copy_elems(temp);
}
template<class Type>
ostream& operator<<(ostream &os, const Queue<Type> &q)
{
    os << "< ";
    QueueItem<Type> *p;
    for(p = q.head; p; p->next)
    {
        os << p->item << "";
    }
    os << ">";
    return os;
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

