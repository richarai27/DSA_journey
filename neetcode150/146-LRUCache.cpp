class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(NULL), next(NULL) {}
};


class LRUCache {
  //Combining a Hash Map for O(1) lookup with a Doubly Linked List for O(1) insertion and deletion to manage cache order
  // Time Complexity: O(1) for both get and put operations
  // Space Complexity: O(capacity) for the cache and the doubly linked list
private:
    int cap;
    unordered_map <int, Node*> cache;
    Node* right;
    Node* left;

    void remove(Node* node){
        Node* pre = node->prev;
        Node* nxt = node->next;
        pre->next = nxt;
        nxt->prev = pre;
    }

    void insert(Node* node){
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if (cache.size() > cap) {
            Node* leastrecentlyused = left->next;
            remove(leastrecentlyused);
            cache.erase(leastrecentlyused->key);
            delete leastrecentlyused;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */