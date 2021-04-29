// boost库中noncopyable使用
 #include <boost/utility.hpp>
 #include <iostream>
using namespace std;
class myclass : public boost::noncopyable {
public:
    myclass() {}
    myclass(int i) {}
};

int main() {
    myclass c1();
    myclass c2(1);
    // myclass c3(c1);
    // myclass c3 = c1;
    return 0;
}
