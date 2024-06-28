class Node:
    def __init__(self):
        self.children = {}
        self.count = 0

class Trie:
    def __init__(self):
        self.root = Node()
    
    def insert(self, s):
        node = self.root
        for ch in s:
            if ch not in node.children:
                node.children[ch] = Node()
            node = node.children[ch]
            node.count += 1
    
    def remove(self, s):
        node = self.root
        nodes = [node]
        for ch in s:
            if ch not in node.children:
                return
            node = node.children[ch]
            nodes.append(node)
        
        if nodes[-1].count == 0:
            return
        
        for i in range(len(s), -1, -1):
            nodes[i].count -= 1
            if nodes[i].count == 0 and i > 0:
                del nodes[i-1].children[s[i-1]]
    
    def count_prefix(self, s):
        node = self.root
        for ch in s:
            if ch not in node.children or node.children[ch].count == 0:
                return 0
            node = node.children[ch]
        return node.count
        
t = int(input())
trie = Trie()
for _ in range(t):
    cmd, s = input().split()
    if cmd == '1':
        trie.insert(s)
    elif cmd == '2':
        trie.remove(s)
    elif cmd == '3':
        print(trie.count_prefix(s))