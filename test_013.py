#!/usr/bin/env python
# coding=utf-8

def sxh_number():
    for n in range(100,1000):
        i = n // 100
        j = n // 10%10
        k = n % 10
        if n==i*i*i + j*j*j + k*k*k:
            print(n)
sxh_number()
