'''
Author       : Daniel_Elendeer
Date         : 2020-10-17 15:37:54
LastEditors  : Daniel_Elendeer
LastEditTime : 2020-10-17 16:13:31
Description  :
'''

from functools import reduce

if __name__ == "__main__":
    print("Input sets, input # to end input:")
    s = set()
    lst = []
    while s != {'#'}:
        s = set(input().split())
        lst.append(s)

    lst.pop()

    print(reduce(lambda s1, s2: s1.union(s2), lst))