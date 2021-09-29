#!/usr/bin/env python
# coding=utf-8
def fib(n):
    a,b=1,1
    for i in range(n-1):
        a,b=b,a+b
    return a
print (fib(10))

def fib2(n):
    if(n==1 or n==2):
        return 1;
    return fib2(n-1) + fib2(n-2)
print(fib2(10))

