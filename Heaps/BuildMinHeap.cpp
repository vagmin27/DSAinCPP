#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    // Compare with left child
    if (left < n && arr[smallest] > arr[left]) {
        smallest = left;
    }
    // Compare with right child
    if (right < n && arr[smallest] > arr[right]) {
        smallest = right;
    }
    // If the smallest is not the current node, swap and heapify
    if (smallest != i) {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest); // Recursively heapify the affected subtree
    }
}
vector<int> buildMinHeap(vector<int> &arr) {
    int n = arr.size();
    // Start heapifying from the last non-leaf node (n/2 - 1)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    return arr;
}
int main() {
    vector<int> arr = {4, 10, 3, 5, 1};
    // Build the Min Heap
    vector<int> minHeap = buildMinHeap(arr);
    // Print the Min Heap
    for (int num : minHeap) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}