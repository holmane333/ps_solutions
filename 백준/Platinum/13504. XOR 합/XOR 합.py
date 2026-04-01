import sys;input = lambda: sys.stdin.readline().rstrip()


class TrieNode:
    def __init__(self):
        self.data = None
        self.children = [None, None]


class Trie:
    def __init__(self):
        self.head = TrieNode()

    def _parse(self, num):
        ary = []
        for i in range(34):
            ary.append(num & 1)
            num >>= 1
        return list(reversed(ary))

    def insert(self, num):
        curr = self.head
        ary = self._parse(num)

        for x in ary:
            if (curr.children[x] is None):
                curr.children[x] = TrieNode()
            curr = curr.children[x]

    def search(self, num):
        curr = self.head
        val = 0
        ary = self._parse(num)
        for idx in range(34):
            x = ary[idx]
            if (not(curr.children[x ^ 1] is None)):
                val |= (1 << (33 - idx))
                curr = curr.children[x ^ 1]
            else:
                curr = curr.children[x]
        return val

ans = []
for tc in range(int(input())):
    res = 0
    N = int(input())
    T = Trie()
    T.insert(0)
    l = [*map(int, input().split())]
    for i in range(1, N): l[i] ^= l[i - 1]
    for a in l:
        T.insert(a)
        res = max(res, T.search(a))
    ans.append(str(res))
print('\n'.join(ans))
