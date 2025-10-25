def solution(phone_book):
    answer = True
    d = dict()
    for i in phone_book:
        s = ""
        for j in range(len(i) - 1):
            s += i[j]
            d[s] = 1
    for i in phone_book:
        if (i in d):
            answer = False
    return answer