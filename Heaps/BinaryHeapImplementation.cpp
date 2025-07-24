#include<bits/stdc++.h>
using namespace std;

class MinHeap {
public:
    int* harr;       // Pointer to array of elements in heap
    int heap_size;   // Current number of elements in heap
    int capacity;    // Maximum possible size of min heap

    // Utility functions
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    void MinHeapify(int i);
    MinHeap(int cap);                   // Constructor to create a min heap of given capacity
    ~MinHeap();                         // Destructor to free memory
    int extractMin();                   // Extract the minimum element (root)
    void deleteKey(int i);              // Delete the key at index i
    void insertKey(int k);              // Insert a new key
    void decreaseKey(int i, int new_val); // Decrease the value at index i
};

// Constructor to initialize the heap
MinHeap::MinHeap(int cap) {
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

// Destructor to free memory
MinHeap::~MinHeap() {
    delete[] harr;
}

// Function to extract the minimum element (root of the heap)
int MinHeap::extractMin() {
    if (heap_size <= 0)
        return INT_MAX;  // or throw exception
    if (heap_size == 1) {
        heap_size--;
        return harr[0];
    }

    // Store the minimum value and remove it from the heap
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);  // Call MinHeapify on the root to restore the heap property
    return root;
}

// Function to delete a key at index i
void MinHeap::deleteKey(int i) {
    decreaseKey(i, INT_MIN);  // Decrease the value to INT_MIN (or the smallest possible value)
    extractMin();  // Now extract the minimum element (which will be the deleted element)
}

// Function to insert a new key
void MinHeap::insertKey(int k) {
    if (heap_size == capacity) {
        cout << "Overflow: Could not insert key\n";
        return;
    }
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

// Function to decrease the key at index i to new_val
void MinHeap::decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

// MinHeapify function to maintain the heap property after a swap or deletion
void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap_size && harr[l] < harr[i]) smallest = l;
    if (r < heap_size && harr[r] < harr[smallest]) smallest = r;

    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}

// A utility function to print the heap (for debugging purposes)
void MinHeap::printHeap() {
    for (int i = 0; i < heap_size; i++)
        cout << harr[i] << " ";
    cout << endl;
}
// Example usage of MinHeap
int main() {
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << "Min value extracted: " << h.extractMin() << endl;
    h.printHeap();
    return 0;
}