#!/usr/bin/python3

if __name__ == '__main__':
	arrayA = [1, 2, 3, 4, 5, 6, 7, 8, 9]

	arrayB = list(arrayA[3:7])
	arrayB.sort(reverse = True)
	print(arrayB)

