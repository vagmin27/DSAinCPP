#include <bits/stdc++.h>
using namespace std;
int getKthLargest(vector<int> &arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (pq.size() < k) {
                pq.push(sum);
            } else {
                if (sum > pq.top()) {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}
int main() {
    vector<int> arr = {1, 2, 3, 4}; // Example array
    int k = 3;                     // Example value of k
    cout << "The " << k << "rd largest sum of subarrays is: " << getKthLargest(arr, k) << endl;
    return 0;
}