#!/usr/bin/python3

num = int(input())

print("Output: ")
while num != 0:
    print(num % 10)
    num //= 10
