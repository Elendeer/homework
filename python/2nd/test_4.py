'''
Author       : Daniel_Elendeer
Date         : 2020-09-20 22:02:21
LastEditors  : Daniel_Elendeer
LastEditTime : 2020-09-20 23:47:53
Description  :
'''
#!/usr/bin/python3

if __name__ == '__main__':
    a1, q, n = map(int, input().split(" "))
    print(int(a1 * (1 - int(pow(q, n))) / (1 - q)))
