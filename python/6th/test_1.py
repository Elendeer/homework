'''
Author       : Daniel_Elendeer
Date         : 2020-10-17 15:37:50
LastEditors  : Daniel_Elendeer
LastEditTime : 2020-10-17 15:49:36
Description  :
'''

if __name__ == "__main__":
    s1 = set()
    print("Input s1:")
    s = input().split()
    for i in s:
        s1.add(i)

    s2 = set()
    print("Input s2:")
    s = input().split()
    for i in s:
        s2.add(i)

    print("Intersection: " + str(s1.intersection(s2)))
    print("Union: " + str(s1.union(s2)))
    print("Difference :")
    print("s1 - s2: " + str(s1.difference(s2)))
    print("s2 - s1: " + str(s2.difference(s1)))