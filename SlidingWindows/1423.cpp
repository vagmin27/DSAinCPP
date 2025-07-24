#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lSum = 0;
        int rSum = 0;
        int lEnd = 0;

        // Initial left sum (first k elements)
        for(int i = 0; i < k; i++) {
            lSum += cardPoints[i];
            lEnd++;
        }
        lEnd--;

        int rEnd = cardPoints.size() - 1;
        int maxSum = lSum;

        // Slide window: remove from left, add from right
        for(int i = k - 1; i >= 0; i--) {
            lSum = lSum - cardPoints[lEnd] + cardPoints[rEnd];
            maxSum = max(lSum, maxSum);
            lEnd--;
            rEnd--;
        }

        return maxSum;
    }
};

int main() {
    Solution solution;

    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    int result = solution.maxScore(cardPoints, k);
    cout << "Maximum score: " << result << endl;

    return 0;
}
