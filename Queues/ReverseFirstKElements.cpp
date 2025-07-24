#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int> s;
        int n = q.size();
        // Step 1: Pop first k elements from queue and push them onto stack
        for (int i = 0; i < k; i++) {
            int val = q.front();
            q.pop();
            s.push(val);
        }
        // Step 2: Pop from stack and push back to queue
        while (!s.empty()) {
            int val = s.top();
            s.pop();
            q.push(val);
        }
        // Step 3: Move the remaining elements to the back of the queue
        int t = n - k;
        while (t--) {
            int val = q.front();
            q.pop();
            q.push(val);
        }
        return q;
    }
};

int main() {
    Solution sol;
    queue<int> q;
    // Sample input
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    int k = 3;
    // Modify the queue
    queue<int> modifiedQueue = sol.modifyQueue(q, k);
    // Output the modified queue
    while (!modifiedQueue.empty()) {
        cout << modifiedQueue.front() << " ";
        modifiedQueue.pop();
    }
    return 0;
}