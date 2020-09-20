'''
Author       : Daniel_Elendeer
Date         : 2020-09-20 22:02:21
LastEditors  : Daniel_Elendeer
LastEditTime : 2020-09-20 23:45:43
Description  :
'''
#!/usr/bin/python3

if __name__ == '__main__':
    res = 1
    for num in map(int, input().split(" ")):
        res *= num

    print(res)
