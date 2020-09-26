'''
Author       : Daniel_Elendeer
Date         : 2020-09-20 22:02:21
LastEditors  : Daniel_Elendeer
LastEditTime : 2020-09-20 23:46:44
Description  :
'''
#!/usr/bin/python3

if __name__ == '__main__':
    x1, y1 = map(int, input().split(" "))
    x2, y2 = map(int, input().split(" "))

    print(abs(x1 - x2) + abs(y1 - y2))
