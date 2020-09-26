'''
Author       : Daniel_Elendeer
Date         : 2020-09-17 13:06:24
LastEditors  : Daniel_Elendeer
LastEditTime : 2020-09-20 23:28:11
Description  :
'''
#!/usr/bin/python3

num = int(input())

print("Output: ")
while num != 0:
    print(num % 10)
    num //= 10
