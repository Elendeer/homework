#!/usr/bin/python3

import random

if __name__ == '__main__':
	rnum = random.randint(1, 100)
	print("I have a number in range 1 to 100, and you have 6 chances to guess it.")
	print("Now please enter you number: ")

	for t in range(0, 6):
		flag = False
		t += 1
		num = int(input())
		if num == rnum:
			print("Succeed!")
			flag = True
			break
		elif num > rnum:
			print("Wrong, your input is bigger then the anser.")
		elif num < rnum:
			print("Wrong, your input is smaller then the anser.")
		
	if not flag:
		print("LOSE! SUCK YOU ARE!")

