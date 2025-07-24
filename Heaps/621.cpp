#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Frequency array to count occurrences of each task
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        // Max-heap (priority queue) to store task frequencies
        priority_queue<int> maxHeap;
        for (int count : freq) {
            if (count > 0) {
                maxHeap.push(count);
            }
        }
        int time = 0;
        while (!maxHeap.empty()) {
            vector<int> temp;
            int cycleTime = n + 1;  // Each cycle can execute n + 1 tasks (1 task and n idle slots)
            // Try to schedule tasks within the current cycle
            for (int i = 0; i < cycleTime; i++) {
                if (!maxHeap.empty()) {
                    int count = maxHeap.top();
                    maxHeap.pop();
                    if (count > 1) {
                        temp.push_back(count - 1);  // Add remaining frequency of task
                    }
                }
            }
            // Push remaining tasks back into the max-heap
            for (int count : temp) {
                maxHeap.push(count);
            }
            // If there are tasks left in the heap, we need to continue, otherwise we are done
            time += maxHeap.empty() ? temp.size() : cycleTime;
        }
        return time;
    }
};
int main() {
    Solution sol;
    // Example 1: Task list with a cooldown of 2
    vector<char> tasks1 = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n1 = 2;
    cout << "Least interval for tasks1: " << sol.leastInterval(tasks1, n1) << endl;
    // Example 2: Task list with a cooldown of 0 (no cooldown)
    vector<char> tasks2 = {'A', 'B', 'C', 'D'};
    int n2 = 0;
    cout << "Least interval for tasks2: " << sol.leastInterval(tasks2, n2) << endl;
    // Example 3: Task list with a higher cooldown
    vector<char> tasks3 = {'A', 'A', 'A', 'A', 'B', 'C'};
    int n3 = 3;
    cout << "Least interval for tasks3: " << sol.leastInterval(tasks3, n3) << endl;
    return 0;
}