'''
Author       : Daniel_Elendeer
Date         : 2020-12-14 21:53:05
LastEditors  : Daniel_Elendeer
LastEditTime : 2020-12-14 22:25:23
Description  :
'''

from random import choice

# 生成一个含两个goat，一个car的排列随机的列表
def createList() :
    st = ["goat", "goat", "car"] # set
    lst = []
    while len(st) != 0:
        item = choice(st)
        st.remove(item)
        lst.append(item)

    return lst


if __name__ == "__main__" :
    lst = createList()
    print(lst)
    print("Peek a door, input 1, 2, or 3:")
    # 注意下标的偏移
    num = int(input()) - 1
    # 输入不合法时抛出异常
    try:
        assert 0 <= num <= 2
    except:
        print("input error")

    # 主持人找到藏有山羊的门
    goat_num = 0
    for i in range(0, 3) :
        if i != num and lst[i] == "goat":
            goat_num = i
            print("It's a goat in door {}".format(i + 1))
            break

    print("Want to change you number to another one? y/n")
    c = input()
    try:
        assert c == "y" or c == "n"
    except:
        print("input error")

    if c == "y":
        for i in range(0, 3):
            if i != num and i != goat_num:
                print("You choosed : {}".format(lst[i]))

    else :
        print("You choosed : {}".format(lst[num]))