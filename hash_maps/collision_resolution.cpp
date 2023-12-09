#include <iostream>
#include <list>
#include <vector>

class HashMap {
private:
    std::vector<std::list<std::pair<int, int>>> table;
    int size;

    int hash(int key) {
        return key % size;
    }

public:
    HashMap(int initialSize) : size(initialSize) {
        table.resize(size);
    }

    void insert(int key, int value) {
        int index = hash(key);
        for (auto& kvPair : table[index]) {
            if (kvPair.first == key) {
                // Update value if key exists
                kvPair.second = value;
                return;
            }
        }
        table[index].emplace_back(key, value);
    }

    int get(int key) {
        int index = hash(key);
        for (const auto& kvPair : table[index]) {
            if (kvPair.first == key) {
                return kvPair.second;
            }
        }
        return -1; // Key not found
    }

    void remove(int key) {
        int index = hash(key);
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};

int main() {
    HashMap map(10);

    map.insert(5, 100);
    map.insert(2, 200);
    map.insert(15, 300);

    std::cout << "Value for key 2: " << map.get(2) << std::endl;
    std::cout << "Value for key 10: " << map.get(10) << std::endl;

    map.remove(5);
    std::cout << "Value for key 5 after removal: " << map.get(5) << std::endl;

    return 0;
}
