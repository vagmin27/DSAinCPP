#include<bits/stdc++.h>
using namespace std;
vector<int> count_NGE(int n, vector<int>& arr, int q, vector<int>& idx) {
    vector<int> cnt(n, 0);
    vector<int>sort; // To maintain elements to the right in sorted order
    for(int i=n-1;i>=0;--i) {
        // Use binary search to find the count of elements greater than arr[i]
        auto it = upper_bound(sort.begin(),sort.end(), arr[i]);
        cnt[i] =sort.end() - it; // Elements to the right that are greater
        // Insert current element in sorted order
        sort.insert(it, arr[i]);
    }
    vector<int> result;
    for (int i=0;i<q;++i) {
        result.push_back(cnt[idx[i]]);
    }
    return result;
}
int main() {
    vector<int> arr = {3, 4, 2, 7, 5, 8, 10, 6};
    vector<int> idx = {0, 5};
    int q = idx.size();
    vector<int> result = count_NGE(arr.size(), arr, q, idx);
    for (int r : result) {
        cout << r << " ";
    }
    return 0;
}