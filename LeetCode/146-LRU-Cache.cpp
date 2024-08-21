class Node {
public:    
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int k, int v){
        key = k;
        value = v;
        next = nullptr;
        prev = nullptr;
    }
};


class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;

    void remove(Node* node){
        Node* prevNode = node -> prev;
        Node* nextNode = node -> next;
        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
    }

    void insert(Node* node){
        Node* nextNode = left -> next;
        left -> next = node;
        node -> next = nextNode;
        nextNode -> prev = node;
        node -> prev = left;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        left -> next = right;
        right -> prev = left;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()){
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node -> value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()){
            Node* node = cache[key];
            node -> value = value;
            remove(node);
            insert(node);
        } else{
            Node* newNode = new Node(key, value);
            insert(newNode);
            cache[key] = newNode;

            if (cache.size() > cap) {
                Node* lru = right -> prev;
                remove(lru);
                cache.erase(lru->key);
                delete lru;
            }
        }
    }
};
