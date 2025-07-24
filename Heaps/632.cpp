#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    int row;
    int col;
    Node(int d, int r, int c) {
        data = d;
        row = r;
        col = c;
    }
};

class compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        priority_queue<Node*, vector<Node*>, compare> pq;
        for (int i = 0; i < nums.size(); i++) {
            int ele = nums[i][0];
            mini = min(mini, ele);
            maxi = max(maxi, ele);
            pq.push(new Node(ele, i, 0));
        }
        int start = mini;
        int end = maxi;
        while (!pq.empty()) {
            Node* temp = pq.top();
            pq.pop();
            mini = temp->data;
            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }
            if (temp->col + 1 < nums[temp->row].size()) {
                int nextEle = nums[temp->row][temp->col + 1];
                maxi = max(maxi, nextEle);
                pq.push(new Node(nextEle, temp->row, temp->col + 1));
            } else {
                break;
            }
        }
        return {start, end};
    }
};

int main() {
    // Example input
    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };
    Solution sol;
    vector<int> result = sol.smallestRange(nums);
    // Output the result
    cout << "Smallest range: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}