#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            pq.push({it->second, it->first});
        }
        string res;
        while (!pq.empty()) {
            auto [occ, ch] = pq.top();
            pq.pop();
            res.append(occ, ch); // Corrected line
        }
        return res;
    }
};
int main() {
    Solution solution;
    string input = "tree";
    string result = solution.frequencySort(input);
    cout << result << endl; // Example usage
    return 0;
}