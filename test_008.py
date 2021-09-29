#!/usr/bin/env python
# coding=utf-8
def print_mul_table():
    for i in range(1,10):
        for j in range(1,i+1):
            print(" %d*%d=%d" % (j,i,i*j),end="")
        print()
print(print_mul_table())

