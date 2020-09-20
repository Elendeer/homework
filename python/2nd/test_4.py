#!/usr/bin/python3

if __name__ == '__main__':
    a1, q, n = map(int, input().split(" "))
    print(int(a1 * (1 - int(pow(q, n))) / (1 - q)))
