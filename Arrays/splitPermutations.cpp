#include <iostream>
#include <vector>
using namespace std;

vector<int> generate_max_goodness_permutation(int N) {
    vector<int> permutation(N);
    for (int i = 0; i < N; ++i) {
        permutation[i] = N - i;
    }
    return permutation;
}

int main() {
    int T;
    cin >> T;
    vector<vector<int>> results;
    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        vector<int> permutation = generate_max_goodness_permutation(N);
        results.push_back(permutation);
    }
    for (auto& result : results) {
        for (int i = 0; i < result.size(); ++i) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
}

