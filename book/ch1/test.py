#!/usr/bin/env python
# -*- coding=utf8 -*-
"""
# Author: luning
# Created Time : 四 11/ 7 17:25:32 2019
# File Name: test.py
# Description:
"""
import pytest
from ch1 import at001_math as math

def test_isLeapYear():
    assert math.isLeapYear(2000)
    assert math.isLeapYear(1000) == False
    assert math.isLeapYear(400)

def test_fibonacci():
    assert math.fibonacci(1) == [1]
