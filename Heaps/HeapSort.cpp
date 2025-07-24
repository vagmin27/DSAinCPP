#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Heapify function to maintain max-heap property
    void heapify(int arr[], int n, int i) {
        int largest = i;  // Initialize largest as root
        int left = 2 * i + 1;  // Left child index (0-indexed)
        int right = 2 * i + 2; // Right child index (0-indexed)
        // If left child is larger than root
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        // If right child is larger than root or left child
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        // If largest is not root, swap and continue heapifying
        if (largest != i) {
            swap(arr[i], arr[largest]);  // Swap root with largest child
            heapify(arr, n, largest);    // Recursively heapify the affected sub-tree
        }
    }
    // Function to build a max heap from an unsorted array
    void buildHeap(int arr[], int n) {
        // Start from the last non-leaf node and heapify each node
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }
    // Function to perform heap sort
    void heapSort(int arr[], int n) {
        buildHeap(arr, n);  // Build a max heap
        // One by one extract elements from the heap
        int size = n;
        while (size > 1) {
            // Step 1: Swap the root (largest element) with the last element
            swap(arr[0], arr[size - 1]);
            size--;  // Decrease the heap size
            // Step 2: Heapify the root of the tree
            heapify(arr, size, 0);
        }
    }
    // Function to print the array (for testing purposes)
    void printArray(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Solution sol;
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    sol.printArray(arr, n);
    sol.heapSort(arr, n);
    cout << "Sorted array: ";
    sol.printArray(arr, n);
    return 0;
}