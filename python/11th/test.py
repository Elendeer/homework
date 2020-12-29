'''
Author       : Daniel_Elendeer
Date         : 2020-12-28 21:54:53
LastEditors  : Daniel_Elendeer
LastEditTime : 2020-12-28 22:27:28
Description  :
'''

class Vector:
    def __init__(self, x, y, z):
        self.__x = x
        self.__y = y
        self.__z = z

    def getX(self):
        return self.__x

    def getY(self):
        return self.__y

    def getZ(self):
        return self.__z

    def __add__(self, other):
        return Vector(self.__x + other.getX(), self.__y + other.getY(), self.__z + other.getZ())

    def __sub__(self, other):
        return Vector(self.__x - other.getX(), self.__y - other.getY(), self.__z - other.getZ())

    def __mul__(self, other):
        return Vector(self.__x * other, self.__y * other, self.__z * other)

    def __truediv__(self, other):
        return Vector(self.__x / other, self.__y / other, self.__z / other)

    def getLength(self):
        return (self.__x ** 2 + self.__y ** 2 + self.__z ** 2) ** 0.5

if __name__ == "__main__":
    v1 = Vector(1, 1, 1)
    v2 = Vector(2, 2, 2)
    print("v1 : (1, 1, 1)")
    print("v2 : (2, 2, 2)")

    v3 = v1 + v2
    print("v1 + v2 = ({}, {}, {})".format(v3.getX(), v3.getY(), v3.getZ()))

    v3 = v1 - v2
    print("v1 - v2 = ({}, {}, {})".format(v3.getX(), v3.getY(), v3.getZ()))

    v3 = v2 * 2
    print("v1 * 2 = ({}, {}, {})".format(v3.getX(), v3.getY(), v3.getZ()))

    v3 = v2 / 2
    print("v1 / 2 = ({}, {}, {})".format(v3.getX(), v3.getY(), v3.getZ()))

    print("Length of v1 : {}".format(v1.getLength()))
