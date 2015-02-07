//https://oj.leetcode.com/problems/lru-cache/

struct CacheNode {
    int prev;
    int next;
    int val;
    CacheNode() {}
    CacheNode(int prev, int next, int val) 
    : prev(prev), next(next), val(val) {}
};
class LRUCache{
private:
    unordered_map<int, CacheNode> _memory;
    int _capacity;
    int _used;
    int _head;
    int _end;

    void _addHead(int key, int val) {
        if (_used == 0) {
            CacheNode node(key, key, val);
            _head = key;
            _end = key;
            _memory.insert(make_pair(key, node));
            _used++;
            return;
        }

        CacheNode& head = _memory[_head];
        CacheNode& end = _memory[_end];
        CacheNode node(_end, _head, val);

        end.next = key;
        head.prev = key;
        _head = key;
        _memory.insert(make_pair(key, node));
        _used++;
    }

    CacheNode& _toHead(int key) {
        if (key == _head) return _memory[_head];

        CacheNode& node = _memory[key];
        CacheNode& beforeNode = _memory[node.prev];
        CacheNode& afterNode = _memory[node.next];

        beforeNode.next = node.next;
        afterNode.prev = node.prev;
        if (_end == key) _end = node.prev;

        CacheNode& head = _memory[_head];
        CacheNode& end = _memory[_end];
        head.prev = key;
        end.next = key;
        node.prev = _end;
        node.next = _head;
        _head = key;

        return _memory[_head];
    }

    void _deleteLast() {
        if (_used == 0) return;

        CacheNode& head = _memory[_head];
        CacheNode& end = _memory[_end];
        CacheNode& beforeEnd = _memory[end.prev];
        beforeEnd.next = _head;
        head.prev = end.prev;
        _memory.erase(_end);
        _end = head.prev;
        _used--;
    }

public:
    LRUCache(int capacity) : _capacity(capacity), _used(0) {
        _memory.reserve(capacity);
    }

    int get(int key) {
        if (_memory.find(key) == _memory.end()) return -1;
        return _toHead(key).val;
    }

    void set(int key, int value) {
        if (_memory.find(key) != _memory.end()) {
            _toHead(key).val = value;
            return;
        }

        if (_used >= _capacity) _deleteLast();

        _addHead(key, value);
    }
};
