#include<bits/stdc++.h>
using namespace std;
class MedianFinder {
public:
    priority_queue<int> maxHeap; // Max-heap for the smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap for the larger half
    MedianFinder() {}
    void addNum(int num) {
        maxHeap.push(num);
        // Balance maxHeap and minHeap
        if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        // Ensure maxHeap has at most one more element than minHeap
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};
int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << "Median: " << mf.findMedian() << endl; // Output: 1.5
    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl; // Output: 2
    mf.addNum(4);
    cout << "Median: " << mf.findMedian() << endl; // Output: 2.5
    return 0;
}