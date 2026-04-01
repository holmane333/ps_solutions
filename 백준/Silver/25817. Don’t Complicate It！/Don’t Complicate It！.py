from sys import stdin

s = stdin.readline().strip().replace(" ", "")
res = 0
st = [0]
for i in s:
    if (i == '('):
        st.append(1)
    elif (i == ')'):
        t = st.pop()
        res += t
        st[-1] = max(st[-1], t + 1)

print(res)
