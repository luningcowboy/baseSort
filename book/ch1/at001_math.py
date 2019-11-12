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

"""
最大公约数: 指两个或多个整数共有约数中最大的一个。
约数: 整数a除以整数b,得到的商正好是整数而没有余数.
"""
# b 是否是 a 的约数
def approximateNumber(a, b):
    if not a % b:
        return True
    return False
# 最大公约数
def maxCommonDivisor(m, n):
    while True:
        remainder = m % n
        if not remainder:
            return n
        else:
            m, n = n, remainder
# 最小公倍数
def minCommonMultiple(m, n):
    return m * n / maxCommonDivisor(m, n)

"""
素数: 除了1和它本身不再有其他因数的自然数
"""
# 判断一个数是否是素数
def isprime(n):
    ret = True
    for i in range(n / 2, 1, -1):
        if n % i == 0:
            ret = False
            break
    return ret
# 获取n的所有因子
def getfactors(n):
    ret = [n]
    for i in range(n / 2, 0, -1):
        if n % i == 0:
            ret.append(i)
    return ret
# 素因子分解
def decompose(n):
    all_factors = getfactors(n)
    all_factors.remove(1)
    all_factors.remove(n)
    prime_factors = [x for x in all_factors if isprime(x)]
    prime_factors.sort(reverse=True)
    result = []
    remainder = n
    for f in prime_factors:
        while remainder >= f:
            qut, rem = divmod(remainder, f)
            if rem != 0:
                break
            else:
                remainder = qut
                result.append(f)
    return result
# 斐波那契数列
def fibonacci(n):
    ret = []
    if n == 1:
        ret.append(1)
    elif n >= 2:
        ret.append(1)
        ret.append(1)
        for i in range(2, n):
            ret.append(ret[-1] + ret[-2])
    return ret
