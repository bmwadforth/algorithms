# Hash Maps

Hash maps, also known as hash tables, are data structures that store key-value pairs. They use a hash function to map keys to indexes in an array, allowing for efficient retrieval, insertion, and deletion of elements.

Example usage:
```c++
#include <iostream>
#include <vector>
#include <list>

// Hash map implementation using separate chaining for collision resolution
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
```

Common algorithms and operations used with hash maps include:

1. Insertion, Retrieval, and Deletion:
   Insert: Adding a key-value pair into the hash map.
   Get: Retrieving the value associated with a key.
   Remove: Deleting a key-value pair from the hash map.
2. Collision Resolution:
   Separate Chaining: Using linked lists (or other structures) at each index to handle collisions.
   Open Addressing: Probing or searching for other locations in the array when a collision occurs.
3. Resize and Rehash:
   Resize: Increasing the size of the underlying array to reduce collisions and improve performance.
   Rehashing: Recalculating hash codes and redistributing elements after resizing.
4. Load Factor and Performance Analysis:
   Load Factor: Measuring how full the hash map is to decide when to resize.
   Performance Analysis: Analyzing time complexity for insertion, retrieval, and deletion operations based on load factor and collision resolution.
   Hash maps are versatile and widely used in various applications, providing fast access to data based on keys. They are fundamental in many programming languages and are used for implementing dictionaries, associative arrays, and more.