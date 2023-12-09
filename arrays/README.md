# Arrays

Arrays are fundamental data structures used to store elements of the same type in contiguous memory locations. They provide quick and direct access to elements using their indices.

Example usage:
```c++
#include <iostream>

int main() {
    // Creating an array of integers
    int arr[5] = {1, 2, 3, 4, 5};

    // Accessing elements of the array using indices
    std::cout << "Element at index 2: " << arr[2] << std::endl;

    // Modifying elements of the array
    arr[3] = 10;

    // Looping through the array
    std::cout << "Array elements: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

Arrays support various common algorithms and operations, such as:

1. Linear Search:
   Searching for a specific element in an array by iterating through each element sequentially.
   Complexity: O(n) for an array of size 'n'.
2. Binary Search (for sorted arrays):
   Searching for an element in a sorted array by repeatedly dividing the search interval in half.
   Complexity: O(log n) for an array of size 'n'.
3. Sorting Algorithms:
   Bubble Sort: Comparing adjacent elements and swapping them if they are in the wrong order.
   Insertion Sort: Iterating through the array and inserting each element into its proper place.
   Selection Sort: Repeatedly selecting the minimum element from the unsorted portion and placing it at the beginning.
   Merge Sort: Dividing the array into smaller arrays, sorting them, and merging them back together.
   Quick Sort: Choosing a 'pivot' element and partitioning the array into two sub-arrays around the pivot.
   Heap Sort: Building a heap and repeatedly extracting the maximum element.
   Counting Sort: Works for arrays with a limited range of elements.
4. Array Manipulation:
   Reversing: Reversing the order of elements in the array.
   Rotation: Shifting elements of the array to the left or right by a specified number of positions.
   Concatenation: Combining two arrays into one.