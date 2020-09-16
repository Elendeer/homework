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


