#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Define a struct to represent each element
    struct Element {
        int value;
        int arrayIndex;
        int elementIndex;
        // Constructor for easy initialization
        Element(int v, int arrIdx, int elemIdx) : value(v), arrayIndex(arrIdx), elementIndex(elemIdx) {}
        // Define the comparison operator for priority_queue to create a min-heap
        bool operator>(const Element& other) const {
            return value > other.value;
        }
    };
    // Function to merge k sorted arrays
    vector<int> mergeKArrays(vector<vector<int>>& arr, int K) {
        // Create a min-heap using the custom struct
        priority_queue<Element, vector<Element>, greater<Element>> minHeap;
        // Insert the first element of each array into the heap
        for (int i = 0; i < K; i++) {
            if (!arr[i].empty()) {
                minHeap.push(Element(arr[i][0], i, 0));  // (value, array index, element index)
            }
        }
        vector<int> result;
        // Process the heap
        while (!minHeap.empty()) {
            // Get the smallest element from the heap
            Element top = minHeap.top();
            minHeap.pop();
            // Add the value to the result
            result.push_back(top.value);
            // If there is another element in the same array, add it to the heap
            if (top.elementIndex + 1 < arr[top.arrayIndex].size()) {
                minHeap.push(Element(arr[top.arrayIndex][top.elementIndex + 1], top.arrayIndex, top.elementIndex + 1));
            }
        }
        return result;
    }
};
int main() {
    Solution solution;
    // Example input: 3 sorted arrays
    vector<vector<int>> arr = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    int K = arr.size();  // Number of arrays
    // Call the function to merge the arrays
    vector<int> result = solution.mergeKArrays(arr, K);
    // Output the result
    cout << "Merged array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}