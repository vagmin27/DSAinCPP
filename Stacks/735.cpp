#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int ast : asteroids) {
            bool destroyed = false;
            // If the current asteroid is moving right
            if (ast > 0) {
                st.push(ast);
            }
            else {
                // Handle the left-moving asteroid
                while (!st.empty() && st.top() > 0) {
                    // Collision case: Right-moving asteroid on stack
                    if (abs(ast) == st.top()) {
                        st.pop();  // Both asteroids destroy each other
                        destroyed = true;
                        break;
                    }
                    else if (abs(ast) > st.top()) {
                        st.pop();  // The right-moving asteroid is destroyed
                    }
                    else {
                        destroyed = true;  // The left-moving asteroid is destroyed
                        break;
                    }
                }
                // If the left-moving asteroid survived the collision checks, add it to the stack
                if (!destroyed) {
                    st.push(ast);
                }
            }
        }
        // Convert the stack to a result vector
        vector<int> result(st.size());
        for (int i = result.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};
int main() {
    Solution solution;
    vector<int> asteroids = {5, 10, -5};  // Example case
    vector<int> result = solution.asteroidCollision(asteroids);
    cout << "Result: ";
    for (int ast : result) {
        cout << ast << " ";
    }
    cout << endl;
    return 0;
}