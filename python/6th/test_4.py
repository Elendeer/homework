'''
Author       : Daniel_Elendeer
Date         : 2020-09-12 22:18:21
LastEditors  : Daniel_Elendeer
LastEditTime : 2020-10-13 22:56:54
Description  :
'''

if __name__ == "__main__":
    lstA = input().split()
    lstB = input().split()

    di = {}
    lenth = 0
    if len(lstA) > len(lstB):
        lenth = len(lstB)
    else:
        lenth = len(lstA)

    for i in range(0, lenth):
        di[lstA[i]] = lstB[i]

    print(di)
