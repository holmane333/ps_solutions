import sys;input = lambda: sys.stdin.readline().rstrip()


class TrieNode:
    def __init__(self):
        self.data = 0
        self.children = {}


class Trie:
    def __init__(self):
        self.head = TrieNode()
        self.ans = 0

    def insert(self, ary):
        curr = self.head

        for x in ary:
            if (curr.children.get(x) is None):
                curr.children[x] = TrieNode()
                self.ans += 1
            curr.data += 1
            curr = curr.children[x]
        curr.data += 1


res = []
while True:
    line = input()
    if not line or line == '0':
        break
        
    T = Trie()
    for i in range(int(line)):
        data = input().split()
        ary = list(reversed(data[1:]))
        T.insert(ary)
        
    res.append(str(T.ans))

print('\n'.join(res))