#!/usr/bin/env python
# -*- coding=utf8 -*-
"""
# Author: luning
# Created Time : 三 11/13 10:58:56 2019
# File Name: at003_duplicate_words.py
# Description:
"""
import sys
def find_count(filename):
    count_map = {}
    with open(filename) as f:
        for line in f:
            if line in count_map:
                count_map[line] += 1
            else:
                count_map[line] = 1
    return {k: v for k, v in count_map.items() if v > 1}

print(find_count('./test.txt'))
