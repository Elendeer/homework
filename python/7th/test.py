'''
Author       : Daniel_Elendeer
Date         : 2020-10-17 16:32:24
LastEditors  : Daniel_Elendeer
LastEditTime : 2020-10-17 22:21:44
Description  :
'''

from itertools import combinations

if __name__ == "__main__":
    num = int(input())
    lst = []

    ops = 0
    while num != 6174:
        lst.clear()
        if num < 0:
            num = (-1) * num

        while num :
            lst.append(num % 10)
            num //= 10

        lst = sorted(lst)
        Max = 0
        Min = 99999
        tmp1 = 0
        for n in lst:
            tmp1 = tmp1 * 10 + n

        tmp2 = 0
        lst.reverse()
        for n in lst:
            tmp2 = tmp2 * 10 + n

        if tmp1 > tmp2:
            Max = tmp1
            Min = tmp2
        else :
            Max = tmp2
            Min = tmp1
        num = Max - Min

        print("Max : " + str(Max))
        print("Min : " + str(Min))
        print("num : " + str(num))
        print("------------")

        ops += 1

    print("times : " + str(ops))
