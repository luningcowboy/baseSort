#!/usr/bin/env python
# -*- coding=utf8 -*-
"""
# Author: luning
# Created Time : 六 11/16 15:38:23 2019
# File Name: at005_nine_number.py
# Description:
"""
def getNums(num):
    ret = []
    a = int(num / 100)
    b = int((num - a * 100) / 10)
    c = int((num - a * 100 - b * 10))
    ret.append(a)
    ret.append(b)
    ret.append(c)
    return ret
def nine_number():
    numbers = [1,2,3,4,5,6,7,8,9]
    for n1 in range(0,len(numbers)):
        for n2 in range(n1 + 1, len(numbers)):
            for n3 in range(n2 + 1, len(numbers)):
                e1 = n1 * 100 + n2 * 10 + n3
                e2 = e1 * 2
                e3 = e1 * 3
                numberInuse = []
                numberInuse.append(n1)
                numberInuse.append(n2)
                numberInuse.append(n3)
                if (not e3 > 987) and (not e1 < 123):
                    e2nums = getNums(e2)
                    e3nums = getNums(e3)
                    for e2num in e2nums:
                        if e2num in numberInuse:
                            break
                        else:
                            numberInuse.append(e2num)
                    for e3num in e3nums:
                        if e3num in numberInuse:
                            break
                        else:
                            numberInuse.append(e3num)
                    #print(e2nums, e3nums)
                    if len(numberInuse) == 9:
                        print(e1, e2, e3)


def nine_number2():
    nine = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    result = []
    for i in nine:
        each1 = 0
        each1 += i * 100
        for j in nine:
            if j == i: continue
            each1 += j * 10
            for k in nine:
                if k == j or k == i: continue
                each1 += k
                each2 = 2 * each1
                each3 = 3 * each1
                if each2 > 999 or each3 > 999: continue
                all_num = []
                all_num.extend(list(str(each1)))
                all_num.extend(list(str(each2)))
                all_num.extend(list(str(each3)))
                num_set = set(all_num)
                if len(num_set) == 9:
                    result.append((each1, each2, each3))
    return result
print(nine_number2())
nine_number()


