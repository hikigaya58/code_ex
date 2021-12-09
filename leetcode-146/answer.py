class Node:
    def __init__(self, key=0, value=0) -> None:
        self.key = key
        self.value = value
        self.prev = None
        self.next = None


class LRUCache:

    def __init__(self, capacity: int):
        self.limit = capacity
        self.size = 0
        self.store: dict[int, Node] = {}
        self.head = Node()
        self.head.prev, self.head.next = -1, -1
        self.store[-2] = self.head
        self.tail = Node()
        self.tail.prev, self.tail.next = -2, -2
        self.store[-1] = self.tail

    def get(self, _key: int) -> int:
        if _key not in self.store or _key == 0 or _key == -1:
            return -1
        else:
            self.moveHead(_key)
            return self.store[_key].value

    def put(self, _key: int, _value: int) -> None:
        if _key not in self.store:
            node = Node(_key, _value)
            self.store[_key] = node
            self.addHead(_key)
            self.size += 1
            if self.size > self.limit:
                self.removeTail()
        else:
            self.store[_key].value = _value
            self.moveHead(_key)

    def addHead(self, _key: int) -> None:
        self.store[_key].next = self.head.next
        self.store[_key].prev = -2
        self.store[self.head.next].prev = _key
        self.head.next = _key

    def moveHead(self, _key: int) -> None:
        prevNode = self.store[_key].prev
        nextNode = self.store[_key].next
        self.store[prevNode].next = nextNode
        self.store[nextNode].prev = prevNode
        self.addHead(_key)

    def removeTail(self) -> None:
        _key = self.tail.prev
        _prev = self.store[_key].prev
        self.store[_prev].next = -1
        self.tail.prev = _prev
        self.store.pop(_key)

        # Your LRUCache object will be instantiated and called as such:
        # obj = LRUCache(capacity)
        # param_1 = obj.get(key)
        # obj.put(key,value)
