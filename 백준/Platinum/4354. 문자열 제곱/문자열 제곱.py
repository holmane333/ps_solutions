ans = []
while (True):
    str1 = list(input())
    if (str1[0] == '.'): break
    sz = len(str1)
    ary = [0 for i in range(sz + 1)]
    index = 0
    for i in range(1, sz):
        while (index > 0 and str1[i] != str1[index]): index = ary[index - 1]
        if (str1[i] == str1[index]): index += 1
        ary[i] = index


    res = sz - ary[sz - 1]
    if (sz % res): ans.append(str(1))
    else: ans.append(str(sz // res))
print('\n'.join(ans))