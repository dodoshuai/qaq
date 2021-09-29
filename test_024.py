#!/usr/bin/env python
# coding=utf-8

a = 1.0
b = 2.0
num = 0
for i in range(1,21):
    num += b/a
    t = b
    b +=a
    a = t
print(num)
