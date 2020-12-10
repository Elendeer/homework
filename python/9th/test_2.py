'''
Author       : Daniel_Elendeer
Date         : 2020-11-21 18:33:18
LastEditors  : Daniel_Elendeer
LastEditTime : 2020-11-21 18:55:46
Description  :
'''

if __name__ == '__main__':
    n, k = map(int, input().split())
    lst = list(range(1, n + 1))
    print(lst)

    idx = 0
    count = k
    while len(lst) != 1:
        count -= 1

        if idx >= len(lst):
            idx = 0

        if count == 0:
            lst.remove(lst[idx])
            print(lst)
            count = k
        else :
            idx += 1

    print(lst.pop())
