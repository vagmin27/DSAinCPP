#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countWays(const string& S) {
    int N = S.length();
    int ways = 0;
    
    // Iterate over possible split positions for Q
    for (int j = 1; j < N; ++j) {
        string P = S.substr(0, j);
        string Q = S.substr(j);
        
        // Calculate R
        string R = Q.substr(P.length());
        
        // Check if P + R = Q
        if (P + R == Q) {
            ways++;
        }
    }
    
    return ways;
}

int main() {
    int T;
    cin >> T;
    
    vector<string> test_cases(T);
    for (int i = 0; i < T; ++i) {
        cin >> test_cases[i];
    }
    
    for (int i = 0; i < T; ++i) {
        string S = test_cases[i];
        int result = countWays(S);
        cout << result << endl;
    }
    
    return 0;
}