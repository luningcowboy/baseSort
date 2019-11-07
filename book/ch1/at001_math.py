#!/usr/bin/env python
# -*- coding=utf8 -*-
"""
# Author: luning
# Created Time : 四 11/ 7 16:36:25 2019
# File Name: 001_math.py
# Description:
"""

# 闰年判断
# 是4的公倍数并且不是100的公倍数的为闰年
# 是400的公倍数
def isLeapYear(year):
    return (not year % 400) or (not year % 4 and year % 100)

# 找零钱
def mod(money):
    cent = int(money * 100)
    all_cent = {25: 0, 10: 0, 5: 0, 1: 0}
    for k in all_cent:
        all_cent[k], cent = divmod(cent, k)
    return all_cent
