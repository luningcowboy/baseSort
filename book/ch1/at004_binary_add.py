#!/usr/bin/env python
# -*- coding=utf8 -*-
"""
# Author: luning
# Created Time : 六 11/16 15:18:09 2019
# File Name: at004_binary_add.py
# Description:
"""
def biAdd(a, b):
    ret = []
    m = 0
    for i in range(len(a)-1, -1, -1):
        m, n = divmod(a[i] + b[i] + m, 2)
        ret.insert(0,n)
    ret.insert(0, m)
    return ret

print(biAdd([0,1,0,1,1,0],[1,1,0,1,1,0]))
