from sys import stdin
l=list(stdin.readline().rstrip())
result=[l[0]]
for i in range(l.count('-')):
    result.append(l[l.index('-')+1])
    l.remove('-')
print(''.join(result))
