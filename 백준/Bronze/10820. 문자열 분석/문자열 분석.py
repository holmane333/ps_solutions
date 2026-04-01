while True:
    try:
        l=[0,0,0,0]
        w=input()
        for i in w:
            t=ord(i)
            if t==32:
                l[3]+=1
            elif 48<=t<=57:
                l[2]+=1
            elif 65<=t<=90:
                l[1]+=1
            else:
                l[0]+=1
        for i in range(len(l)-1):
            print(l[i],end=' ')
        print(l[-1])
    except EOFError:
        break
