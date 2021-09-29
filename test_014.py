#!/usr/bin/env python
# coding=utf-8
def reduceNum(n):
    print ('{} = '.format(n))
    if not isinstance(n,int) or n <=0:
        print('请输入一个正确的数字!')
        exit(0)
    elif n in [1]:
        print('{}'.format(n))
    while n not in [1]:
        for index in range(2,int(n)+1):
            if n % index == 0:
                n /= index
                if n == 1 :
                    print(index)
                else :
                    print('{} * '.format(index),end="")
                break
reduceNum(90)
reduceNum(100)
