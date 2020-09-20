'''
Author       : Daniel_Elendeer
Date         : 2020-09-17 13:06:24
LastEditors  : Daniel_Elendeer
LastEditTime : 2020-09-20 23:33:14
Description  :
'''
#!/usr/bin/python3

string = input()
num = int(string)

print(bin(num))
print(oct(num))
print(hex(num))

print("bin: {0:b}, oct: {0:o}, hex: {0:x}".format(num))
