#!/usr/bin/env python
# coding=utf-8

def math_free_boot(a,b):
    tour = []
    height = []
    hei = a
    tim = b
    for i in range(1, tim + 1):
        if i == 1:
            tour.append(hei)
        else: 
            tour.append(2*hei)
        hei /= 2
        height.append(hei)
    print('总高度:tour = {0}'.format(sum(tour)))
    print('第10次反弹高度: height = {0}'.format(height[-1]))
math_free_boot(200.0,10)
