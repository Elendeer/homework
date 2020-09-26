#!/usr/bin/python3

if __name__ == '__main__':
    string = input()

    others = nums = letters = spaces = 0

    for c in string:
        if c.isnumeric():
            nums += 1
        elif c.isalpha():
            letters += 1
        elif c.isspace():
            spaces += 1
        else :
            others += 1

    print("nums :{}, letters:{}, spaces:{}, others:{}".format(nums, letters, spaces, others))

