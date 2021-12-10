class Node:
    def __init__(self, key=0, value=0) -> None:
        self.key: int = key
        self.value: int = value
        self.prev: Node = None
        self.next: Node = None


class LRUCache:

    def __init__(self, capacity: int):
        self.limit = capacity
        self.size = 0
        self.store: dict[int, Node] = {}
        self.head = Node()
        self.tail = Node()
        self.head.next = self.tail
        self.tail.prev = self.head

    def get(self, _key: int) -> int:
        if _key not in self.store:
            return -1
        else:
            node = self.store[_key]
            self.moveHead(node)
            return node.value

    def put(self, _key: int, _value: int) -> None:
        if _key not in self.store:
            node = Node(_key, _value)
            self.store[_key] = node
            self.addHead(node)
            self.size += 1
            if self.size > self.limit:
                self.removeTail()
                self.size -= 1
        else:
            node = self.store[_key]
            node.value = _value
            self.moveHead(node)

    def removeNode(self, _node: Node) -> None:
        _node.prev.next = _node.next
        _node.next.prev = _node.prev

    def addHead(self, _node: Node) -> None:
        _node.next = self.head.next
        _node.prev = self.head
        self.head.next.prev = _node
        self.head.next = _node

    def moveHead(self, _node: Node) -> None:
        self.removeNode(_node)
        self.addHead(_node)

    def removeTail(self) -> None:
        node = self.tail.prev
        node.prev.next = self.tail
        self.tail.prev = node.prev
        self.store.pop(node.key)

        # Your LRUCache object will be instantiated and called as such:
        # obj = LRUCache(capacity)
        # param_1 = obj.get(key)
        # obj.put(key,value)
