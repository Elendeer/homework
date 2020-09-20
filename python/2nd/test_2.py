#!/usr/bin/python3

if __name__ == '__main__':
    res = 1
    for num in map(int, input().split(" ")):
        res *= num

    print(res)
