#!/usr/bin/python3

import random


def getPi(times):
    hints = 0
    for i in range(1, times + 1):
        y = random.random()
        x = random.random()
        if x * x + y * y <= 1:
            hints += 1
    Pi = hints / times * 4
    return Pi

if __name__ == '__main__':
    times = int(input())
    print(getPi(times))
