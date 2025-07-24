#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int MaximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> indegree(n, 0);
        vector<int> chainLength(n, 0);
        vector<bool> visited(n, false);
        // Calculate indegree for each person
        for (int f : favorite) {
            indegree[f]++;
        }
        // Initialize a queue for processing people with indegree 0
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        // Process chains
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            int fav = favorite[curr];
            chainLength[fav] = max(chainLength[fav], chainLength[curr] + 1);
            indegree[fav]--;
            if (indegree[fav] == 0) {
                q.push(fav);
            }
        }
        int maxCycleLength = 0;
        int chainPairsLength = 0;
        // Process cycles
        for (int i = 0; i < n; i++) {
            if (!visited[i] && indegree[i] > 0) {
                int cycleLength = 0;
                int curr = i;
                do {
                    visited[curr] = true;
                    curr = favorite[curr];
                    cycleLength++;
                }while (curr != i);
                if (cycleLength == 2) {
                    int a = i, b = favorite[i];
                    chainPairsLength += 2 + chainLength[a] + chainLength[b];
                } else {
                    maxCycleLength = max(maxCycleLength, cycleLength);
                }
            }
        }
        return max(maxCycleLength, chainPairsLength);
    }
};

int main() {
    Solution sol;
    vector<int> favorite = {0, 1, 2, 3, 4, 0}; // Example input
    cout << sol.MaximumInvitations(favorite) << endl; // Example output
    return 0;
}