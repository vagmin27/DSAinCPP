#include <iostream>
#include <queue>
using namespace std;

class Solution {
private:
    priority_queue<int> maxHeap; // Max-heap to store the elements
public:
    // Function to add elements to the heap
    void addElement(int num) {
        maxHeap.push(num);
    }
    // Function to extract the maximum element from the heap
    int extractMax() {
        if (maxHeap.empty()) {
            throw runtime_error("Heap is empty! Cannot extract maximum.");
        }
        int maxElement = maxHeap.top(); // Get the maximum element
        maxHeap.pop(); // Remove the maximum element
        return maxElement;
    }
    // Function to check if the heap is empty
    bool isEmpty() {
        return maxHeap.empty();
    }
};
int main() {
    Solution solution;
    solution.addElement(10);
    solution.addElement(20);
    solution.addElement(5);
    cout << "Extracted Max: " << solution.extractMax() << endl; // Output: 20
    cout << "Extracted Max: " << solution.extractMax() << endl; // Output: 10
    cout << "Extracted Max: " << solution.extractMax() << endl; // Output: 5
    try {
        cout << "Extracted Max: " << solution.extractMax() << endl; // Should throw an error
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}