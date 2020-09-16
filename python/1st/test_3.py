#!/usr/bin/python3

string = input()
num = int(string)

print(bin(num))
print(oct(num))
print(hex(num))

print("bin: {0:b}, oct: {0:o}, hex: {0:x}".format(num))
