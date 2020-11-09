'''
Author       : Daniel_Elendeer
Date         : 2020-10-31 21:00:35
LastEditors  : Daniel_Elendeer
LastEditTime : 2020-10-31 21:36:43
Description  :
'''

#!/usr/bin/python3

if __name__ == "__main__":
    origin_str = "arstneio"
    print("oringin string : {}".format(origin_str))

    input_str = input()

    if len(input_str) > len(origin_str) :
        print("error")
        exit()

    # print(len(origin_str))

    i = 0
    count = 0
    while i < len(input_str) :
        if origin_str[i] ==  input_str[i]:
            count += 1
        i += 1

    score = round(count / len(origin_str), 2)
    print("score : {}".format(score))

    print("Level : ", end = "")
    if score >= 0.9:
        print("A")
    elif score >= 0.8:
        print("B")
    elif score >= 0.7:
        print("C")
    elif score >= 0.6:
        print("D")
    else :
        print("E")

