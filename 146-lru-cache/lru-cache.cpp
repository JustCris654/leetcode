#include <unordered_map>

struct Node {
    int k;
    int v;
    Node* prev;
    Node* next;
};


class LRUCache {
private:
    std::unordered_map<int, Node*> items;
    Node* first;
    Node* last;
    int cap;
 
    void addFront(Node* n) {
        n->next = first;
        if (first != nullptr) {
            first->prev = n;
        } else {
            last = n;
        }

        first = n;
    }

    void detach(Node* n) {
        if (n->prev != nullptr) {
            n->prev->next = n->next;
        } else {
            first = n->next;
        }

        if (n->next != nullptr) {
            n->next->prev = n->prev;
        } else {
            last = n->prev;
        }

        n->prev = nullptr;
        n->next = nullptr;
    }

public:
    LRUCache(int capacity)
        : cap(capacity), items(capacity) {
        first = nullptr;
        last = nullptr;
    }

    int get(int key) {
        if (auto search = items.find(key); search != items.end()) {
            Node* n = search->second;
            detach(n);
            addFront(n);

            return search->second->v;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        auto search = items.find(key);

        if (items.size() >= cap && search == items.end()) {
            Node* n = last;
            detach(n);
            addFront(n);
            items.erase(items.find(n->k));
            n->k = key;
            n->v = value;

            items[key] = n;
           
        } else if (search != items.end()) {
            Node* n = search->second;
            detach(n);
            addFront(n);
            n->v = value;
        } else {
            Node* n = new Node{key, value, nullptr, nullptr};
            addFront(n);
            items[key] = n;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {

}
