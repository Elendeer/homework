#!/usr/bin/python3

string = input()

lst = []
for i in map(int, string):
    lst.append(i)

print(sum(lst))

