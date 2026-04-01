import math

def failure(str1, str2, ary):
    global res
    index = 0
    for i in range(len(str2)):
        while (index > 0 and str2[i] != str1[index]): 
            index = ary[index - 1]
        
        if (str2[i] == str1[index]):
            if (index == len(str1) - 1):
                res += 1
                index = ary[index]
            else:
                index += 1

# N = int(input())
str1, str2 = list(input()), list(input())
for i in range(len(str2) - 1):
    str2.append(str2[i])
ary = [0 for i in range(len(str1) + 1)]
index = 0
for i in range(1, len(str1)):
    while (index > 0 and str1[i] != str1[index]): 
        index = ary[index - 1]
    if (str1[i] == str1[index]): 
        index += 1
        ary[i] = index

res = 0
failure(str1, str2, ary)

print(f"{res}")