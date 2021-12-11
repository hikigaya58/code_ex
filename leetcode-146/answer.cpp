#include <iostream>
#include <unordered_map>
#include <memory>

using namespace std;

struct Node
{
    int key = 0;
    int value = 0;
    Node *prev = nullptr;
    Node *next = nullptr;
    Node() = default;
    Node(int _key, int _value) : key(_key), value(_value){};
};

class LRUCache
{
private:
    int size = 0;
    int limit;
    unordered_map<int, shared_ptr<Node>> store;
    Node head = Node();
    Node tail = Node();

    void addHead(Node &_node)
    {
        _node.prev = &head;
        _node.next = head.next;
        head.next->prev = &_node;
        head.next = &_node;
    }

    void removeNode(Node &_node)
    {
        _node.prev->next = _node.next;
        _node.next->prev = _node.prev;
    }

    void takeHead(Node &_node)
    {
        removeNode(_node);
        addHead(_node);
    }

    void removeTail()
    {
        int key = tail.prev->key;
        tail.prev->prev->next = &tail;
        tail.prev = tail.prev->prev;
        store.erase(key);
    }

public:
    LRUCache(int capacity) : limit(capacity)
    {
        head.next = &tail;
        tail.prev = &head;
    }

    int get(int key)
    {
        if (store.count(key) == 0)
            return -1;
        else
        {
            auto &node = store[key];
            takeHead(*node);
            return node->value;
        }
    }

    void put(int key, int value)
    {
        if (store.find(key) == store.end())
        {
            auto node = make_shared<Node>(key, value);
            store[key] = node;
            addHead(*node);
            ++size;
            if (size > limit)
            {
                removeTail();
                --size;
            }
        }
        else
        {
            auto &node = store[key];
            node->value = value;
            takeHead(*node);
        }
    }
};