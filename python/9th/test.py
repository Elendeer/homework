'''
Author       : Daniel_Elendeer
Date         : 2020-11-21 17:55:14
LastEditors  : Daniel_Elendeer
LastEditTime : 2020-11-21 18:31:42
Description  :
'''
import itertools

if __name__ == '__main__':
    n, k = map(int, input().split())

    s = set(range(1, n + 1))
    print(s)
    c = itertools.cycle(range(1, n + 1))

    count = k
    for i in c:
        if len(s) == 1:
            break

        if i in s:
            count -= 1

        if count == 0:
            if i in s:
                s.remove(i)
                print(s)
                count = k


    print(s.pop())

