'''
Author       : Daniel_Elendeer
Date         : 2020-09-17 13:06:24
LastEditors  : Daniel_Elendeer
LastEditTime : 2020-09-20 23:33:02
Description  :
'''
#!/usr/bin/python3

string = input()

lst = []
for i in map(int, string):
    lst.append(i)

print(sum(lst))

