import sys;input=lambda:sys.stdin.readline().rstrip()

class TrieNode:
    def __init__(self):
        self.data = None
        self.children = {}

class Trie:
    def __init__(self):
        self.head = TrieNode()
    
    def insert(self, word):
        curr = self.head
        
        for c in word:
            if (c not in curr.children):
                curr.children[c] = TrieNode()
            curr = curr.children[c]
        curr.data = word
    
    def search(self, word):
        curr = self.head
        
        for c in word:
            if (c in curr.children):
                curr = curr.children[c]
            else:
                return True
            if (curr.data != None):
                return False
        return False

res = []
for _ in range(int(input())):
    N = int(input())
    T = Trie()
    ans = 'YES'
    l = [input() for i in range(N)]
    for a in l:
        if (not T.search(a)):
            ans = 'NO'
            break
        T.insert(a)
    res.append(ans)
print('\n'.join(res))