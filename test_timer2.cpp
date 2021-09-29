#include <iostream>
#include <chrono>
#include <thread>
#include <boost/asio.hpp>


class printer2 {
private:
    boost::asio::steady_timer timer_;
    int count_;
    void print() {
        if (count_ < 10) {
            std::cout << count_ << "\n";
            ++count_;

            timer_.expires_from_now(std::chrono::milliseconds (500));
            timer_.async_wait(std::bind(&printer2::print, this));

        }
        else
        {
            std::cout << "Final count is " << count_ << "\n";
            delete this;

        }

    }
    printer2(boost::asio::io_service &io)
        : timer_(io,std::chrono::milliseconds (500)),
        count_(0) {
            timer_.async_wait(std::bind(&printer2::print, this));


        }
    ~printer2() {


    }

public:

    static printer2* Create(boost::asio::io_service &io){
        return new printer2(io);

    }



};

int main() {
    boost::asio::io_service io;
    printer2::Create(io);
    printer2::Create(io);
    printer2::Create(io);
    printer2::Create(io);
    io.run();
    std::cin.get();
    return 0;

}
