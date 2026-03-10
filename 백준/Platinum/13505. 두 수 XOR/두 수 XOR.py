import sys;input=lambda:sys.stdin.readline().rstrip()

class TrieNode:
    def __init__(self):
        self.data = None
        self.children = {}


class Trie:
    def __init__(self):
        self.head = TrieNode()
    
    
    def _parse(self, num):
        ary = []
        for i in range(40):
            ary.append(num & 1)
            num >>= 1
        return list(reversed(ary))
    
    
    def insert(self, num):
        curr = self.head
        ary = self._parse(num)
        
        for x in ary:
            if (x not in curr.children):
                curr.children[x] = TrieNode()
            curr = curr.children[x]
    
    
    def search(self, num):
        curr = self.head
        val = 0
        ary = self._parse(num)
        for idx in range(40):
            x = ary[idx]
            if ((x ^ 1) in curr.children):
                val |= (1 << (39 - idx))
                curr = curr.children[x ^ 1]
            else:
                curr = curr.children[x]
        return val

res = 0
N = int(input())
T = Trie()
l = [*map(int, input().split())]
for a in l:
    T.insert(a)
for a in l:
    res = max(res, T.search(a))
print(res)