import re
from sys import stdin

reg = re.compile('(100+1+|01)+')
s = stdin.readline().rstrip()
r = reg.fullmatch(s)
if (r):
	print("SUBMARINE")
else:
	print("NOISE")