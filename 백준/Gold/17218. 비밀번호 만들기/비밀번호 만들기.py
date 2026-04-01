from sys import stdin

str1 = str(stdin.readline().rstrip())
str2 = str(stdin.readline().rstrip())

dp = [["" for _ in range(50)] for _ in range(50)]

for i in range(len(str1)):
    for j in range(len(str2)):
        if (str1[i] == str2[j]):
            dp[i + 1][j + 1] = dp[i][j] + str1[i]
        else:
            if (len(dp[i][j + 1]) > len(dp[i + 1][j])):
                dp[i + 1][j + 1] = dp[i][j + 1]
            else:
                dp[i + 1][j + 1] = dp[i + 1][j]
print(dp[len(str1)][len(str2)])
