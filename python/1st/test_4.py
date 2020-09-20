'''
Author       : Daniel_Elendeer
Date         : 2020-09-17 13:06:24
LastEditors  : Daniel_Elendeer
LastEditTime : 2020-09-20 23:34:34
Description  :
'''
#!/usr/bin/python3

if __name__ == '__main__':
    string = input()

    lst = string.split(" ")
    newlst = []
    for item in lst:
        num = int(item)
        if num % 2 == 0:
            newlst.append(num)

    print(newlst)


