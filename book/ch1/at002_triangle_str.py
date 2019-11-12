#!/usr/bin/env python
# -*- coding=utf8 -*-
"""
# Author: luning
# Created Time : 二 11/12 13:30:39 2019
# File Name: at002_triangle_str.py
# Description:
"""

def triangleDisplay(mystr):
    mystr += ' '
    ret = []
    le = len(mystr)
    for i in range(1, le):
        ret.append(mystr[-i:-1])
    for i in range(le):
        ret.append(mystr[i:-1])
    return ret
"""
for e in triangleDisplay("abcdefghijklmnopqrstuvwxyz"):
    print(e)
"""
def triangleDisplay2(width):
    star = "*"
    space = " "
    ret = []
    for i in range(1,width, 2):
        v = ""
        sLen = i
        spaceLen = int((width - i) / 2)
        for k in range(spaceLen):
            v = v + space
        for k in range(sLen):
            v = v + star
        for k in range(spaceLen):
            v = v + space
        ret.append(v)
    return ret
"""
for e in triangleDisplay2(10):
    print(e)
"""



