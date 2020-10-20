'''
Author       : Daniel_Elendeer
Date         : 2020-10-17 15:37:55
LastEditors  : Daniel_Elendeer
LastEditTime : 2020-10-17 16:23:07
Description  :
'''
if __name__ == "__main__":
    string = input()
    dic = {}
    for c in string :
        if c in dic :
            dic[c] += 1
        else :
            dic[c] = 1

    most = 0
    key = 0
    for k in dic:
        if dic[k] > most:
            most = dic[k]
            key = k

    print(key)