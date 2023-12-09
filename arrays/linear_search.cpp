#include <iostream>
#include <vector>

// Linear search function
int linearSearch(const std::vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i; // Return the index if the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

int main() {
    std::vector<int> arr = {5, 8, 3, 9, 2, 7};

    int target = 3;
    int index = linearSearch(arr, target);

    if (index != -1) {
        std::cout << "Target " << target << " found at index " << index << std::endl;
    } else {
        std::cout << "Target " << target << " not found in the array" << std::endl;
    }

    return 0;
}
