import sys;input=lambda:sys.stdin.readline().rstrip()

class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_word = False

class Trie:
    def __init__(self):
        self.head = TrieNode()

    def insert(self, word):
        curr = self.head
        for char in word:
            if curr.children.get(char) is None:
                curr.children[char] = TrieNode()
            curr = curr.children[char]
        curr.is_word = True

n = int(input())

T = Trie()
for _ in range(n):
    T.insert(input())

input()
b = int(input())

dx = [-1, -1, -1, 0, 0, 1, 1, 1]
dy = [-1, 0, 1, -1, 1, -1, 0, 1]
scores = [0, 0, 0, 1, 1, 2, 3, 5, 11]

res = []

for i in range(b):
    board = [input() for _ in range(4)]
    if i < b - 1:
        input()
        
    found = set()
    
    def dfs(x, y, node, visited, current_word):
        if node.is_word:
            found.add(current_word)
        
        for d in range(8):
            nx = x + dx[d]
            ny = y + dy[d]
            if 0 <= nx < 4 and 0 <= ny < 4 and not visited[nx][ny]:
                next_char = board[nx][ny]
                if node.children.get(next_char) is not None:
                    visited[nx][ny] = True
                    dfs(nx, ny, node.children[next_char], visited, current_word + next_char)
                    visited[nx][ny] = False

    for x in range(4):
        for y in range(4):
            char = board[x][y]
            if T.head.children.get(char) is not None:
                visited = [[False] * 4 for _ in range(4)]
                visited[x][y] = True
                dfs(x, y, T.head.children[char], visited, char)
    
    total_score = sum(scores[len(word)] for word in found)
    longest_word = ""
    for word in found:
        if len(word) > len(longest_word) or (len(word) == len(longest_word) and word < longest_word):
            longest_word = word
    
    res.append(f"{total_score} {longest_word} {len(found)}")

print('\n'.join(res))