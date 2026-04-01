for i in range(100):
    try:
        v=input()
        print(v)
    except EOFError:
        break
