#include <iostream>
#include <vector>

class MyHashMap {

private:
    int prime = 2999;
    std::vector<std::vector<std::pair<int, int>>> items;

    int hash(int key) {
        return key % prime;
    }

    // int scan(int key) {
    //     int pos = hash(key);

    //     for (int i = 0; i < key[i].size(); i++) {
    //         if (keys[i] == key) {
    //             return items[pos][i];
    //         }
    //     }

    //     return -1;
    // }

public:
    MyHashMap(): items(prime) {}
    
    void put(int key, int value) {
        int pos = hash(key);

        if (items[pos].size() == 0) { // caso semplice no collisione
            items[pos].push_back(std::make_pair(key, value));
        } else {
            for (int i = 0; i < items[pos].size(); i++) {
                if (items[pos][i].first == key) {
                    items[pos][i].second = value;
                    return;
                }
            }

            items[pos].push_back(std::make_pair(key, value));
        }
    }
    
    int get(int key) {
        int pos = hash(key);

        for (int i = 0; i < items[pos].size(); i++) {
            if (items[pos][i].first == key) {
                return items[pos][i].second;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        int pos = hash(key);

        for (int i = 0; i < items[pos].size(); i++) {
            if (items[pos][i].first == key) {
                items[pos][i] = items[pos].back();

                items[pos].pop_back();
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main() {
    MyHashMap map;
    map.put(1, 1);
    map.put(2, 2);
    int first = map.get(1);  // atteso: 1
    int second = map.get(3); // atteso: -1
    map.put(2, 1);
    int third = map.get(2);  // atteso: 1
    map.remove(2);
    int fourth = map.get(2); // atteso: -1

    std::cout << "[\"MyHashMap\",\"put\",\"put\",\"get\",\"get\",\"put\",\"get\",\"remove\",\"get\"]\n";
    std::cout << "[  [],        [1,1],[2,2],[1],  [3],  [2,1],[2],  [2],     [2]]\n";
    std::cout << "Atteso:   [null,null,null,1,-1,null,1,null,-1]\n";
    std::cout << "Ottenuto: [null,null,null," << first << ',' << second
              << ",null," << third << ",null," << fourth << "]\n";

    return (first == 1 && second == -1 && third == 1 && fourth == -1) ? 0 : 1;
}
