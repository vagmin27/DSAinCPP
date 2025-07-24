#include<bits/stdc++.h>
using namespace std;
int* prevSmaller(int* A, int n1, int *len1) {
    stack<int> s;
    int* result = new int[n1]; // Allocate the result array
    for (int i = 0; i < n1; i++) {
        int curr = A[i];
        // Pop elements from the stack while they are greater than or equal to the current element
        while (!s.empty() && s.top() >= curr) {
            s.pop();
        }
        // If the stack is empty, there is no smaller element
        result[i] = s.empty() ? -1 : s.top();
        // Push the current element onto the stack
        s.push(curr);
    }
    *len1 = n1; // Set the length of the result
    return result; // Return the result array
}

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int length;
    int* result = prevSmaller(arr, 5, &length);
    for (int i = 0; i < length; i++) {
        cout << result[i] << " ";
    }
    delete[] result; // Don't forget to free the allocated memory
    return 0;
}