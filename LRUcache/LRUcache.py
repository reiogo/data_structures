
class Node:

    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.nxt = None
    

class Lru:

    def __init__(self, capacity):

        self.capacity = capacity
        self.hashmap = {}
        self.count = 0
        self.left = Node(0,0)
        self.right = Node(0,0)
        self.left.nxt = self.right
        self.right.prev = self.left


    def remove(self, node):
        prev = node.prev
        nxt = node.nxt
        
        prev.nxt = nxt
        nxt.prev = prev


    def insertAtRight(self, node):
        prev = self.right.prev

        prev.nxt = node
        self.right.prev = node

        node.prev = prev
        node.nxt = self.right

    def put(self, key, value):

        if key in self.hashmap:
            self.remove(self.hashmap[key])

        self.hashmap[key] = Node(key, value)
        self.insertAtRight(self.hashmap[key])

        if self.count >= self.capacity:

            lru = self.left.next
            self.remove(lru)
            del self.hashmap[lru.key]


    def get(self, key):

        if key in self.hashmap:

            node = self.hashmap[key]

            self.remove(node)
            self.insertAtRight(node)

            return self.hashmap[key].value

        return None



