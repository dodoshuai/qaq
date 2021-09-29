#pragma once

class Product;

class Factory
{
public:
    virtual ~Factory()=0;
    virtual Product* CreatProduct()=0;
protected:
    Factory();
private:

};

class ConcreteFactory:public Factory
{
public:
    ~ConcreteFactory();
    ConcreteFactory();
    Product* CreatProduct();
protected:
private:
};
