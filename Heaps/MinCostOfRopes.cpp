#include <bits/stdc++.h>
using namespace std;
int minCost(vector<int>& arr) {
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }
    int cost = 0;
    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int sum = a + b;
        cost += sum;
        pq.push(sum);
    }
    return cost;
}
int main() {
    vector<int> arr = {4, 3, 2, 6}; // Example input
    cout << "Minimum cost to combine elements: " << minCost(arr) << endl;
    return 0;
}