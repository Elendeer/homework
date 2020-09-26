#!/usr/bin/python3

if __name__ == '__main__':
	lst = map(int, input().split(' '))
	
	ans = 1
	for num in lst:
		ans *= num
	
	print("The anser is : {}".format(ans))

