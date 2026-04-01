from sys import stdin

s = stdin.readline().rstrip()

if (len(s) >= 5 and s[len(s) - 5:len(s)] == "driip"):
	print("cute")
else:
	print("not cute")