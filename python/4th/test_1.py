#!/usr/bin/python3

import math

def isPrime(num):
	for i in range(2, int(math.sqrt(num)) + 1):
		if num % i == 0:
			return False

	return True

def function(num):
	lst = []
	for i in range(1, num + 1):
		if isPrime(i):
			lst.append(i)

	return lst



if __name__ == '__main__':
	num = int(input())
	print(function(num))
