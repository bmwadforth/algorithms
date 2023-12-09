#include <iostream>
#include <vector>

// Binary search function (recursive approach)
int binarySearch(const std::vector<int>& arr, int target, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Return the index if the target is found at the midpoint
        }

        if (arr[mid] < target) {
            return binarySearch(arr, target, mid + 1, right); // Search the right half
        } else {
            return binarySearch(arr, target, left, mid - 1); // Search the left half
        }
    }

    return -1; // Return -1 if the target is not found
}

int main() {
    std::vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 23;

    int index = binarySearch(arr, target, 0, arr.size() - 1);

    if (index != -1) {
        std::cout << "Target " << target << " found at index " << index << std::endl;
    } else {
        std::cout << "Target " << target << " not found in the array" << std::endl;
    }

    return 0;
}
