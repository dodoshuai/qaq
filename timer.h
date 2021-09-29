#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <boost/asio.hpp>

class timer
{
public:
    static timer* Create(boost::asio::io_service &io, int ms_num = 500){
        return new timer(io,ms_num);
    }
private:
    boost::asio::steady_timer timer_;
    int count_;
    int mseconds_num;
    timer(boost::asio::io_service& io, int ms = 500)
        : timer_(io,std::chrono::milliseconds(ms)),
        mseconds_num(ms),
        count_(0){
            timer_.async_wait(std::bind(&timer::print, this));
        }
    ~timer() {}
    void print(){
        if(count_ < 10) {
            std::cout <<count_ << "\n";
            ++count_;
            timer_.expires_from_now(std::chrono::milliseconds(mseconds_num));
            timer_.async_wait(std::bind(&timer::print, this));
        }
        else
        {
            std::cout<<"Final count is " << count_ << "\n";
            delete this;
        }
    }

};

