import sys;input = lambda: sys.stdin.readline().rstrip()


class TrieNode:
    def __init__(self):
        self.data = 0
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
            curr.data += 1
            curr = curr.children[x]
        curr.data += 1

    def delete(self, num):
        curr = self.head
        ary = self._parse(num)

        for x in ary:
            curr.data -= 1
            curr = curr.children[x]
        curr.data -= 1

    def search(self, num):
        curr = self.head
        val = 0
        ary = self._parse(num)
        for idx in range(34):
            x = ary[idx]
            if (not (curr.children[x ^ 1] is None) and curr.children[x ^ 1].data):
                val |= (1 << (33 - idx))
                curr = curr.children[x ^ 1]
            else:
                curr = curr.children[x]
        return val


res = []
T = Trie()
T.insert(0)
for i in range(int(input())):
    op, num = map(int, input().split())
    if (op == 1):
        T.insert(num)
    elif (op == 2):
        T.delete(num)
    else:
        res.append(str(T.search(num)))

print('\n'.join(res))