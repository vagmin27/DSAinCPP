#include <bits/stdc++.h>
using namespace std;
// Define the petrolPump structure
struct petrolPump {
    int petrol;   // Amount of petrol at the pump
    int distance; // Distance to the next pump
};
class Solution {
public:
    int tour(petrolPump p[], int n) {
        int deficient = 0; // To track the total deficit of petrol
        int balance = 0;   // Current balance of petrol
        int start = 0;     // Starting point index
        for (int i = 0; i < n; i++) {
            // Update the balance by adding petrol and subtracting distance
            balance += p[i].petrol - p[i].distance;
            // If balance goes negative, reset the starting point
            if (balance < 0) {
                deficient += balance; // Accumulate the deficiency
                start = i + 1;        // Update starting point
                balance = 0;          // Reset balance
            }
        }
        // If the total deficient petrol is less than or equal to the remaining balance,
        // then a valid starting point exists
        if (deficient + balance >= 0) {
            return start;
        }
        else{
            return -1; // Not possible to complete the tour
        }
    }
};

int main() {
    // Create an array of petrolPump
    petrolPump pumps[] = { {4, 6}, {6, 5}, {7, 3}, {4, 5} };
    int n = sizeof(pumps) / sizeof(pumps[0]);
    Solution sol;
    int startingPoint = sol.tour(pumps, n);
    if (startingPoint != -1) {
        cout << "The starting point is: " << startingPoint << endl;
    }
    else {
        cout << "Not possible to complete the tour" << endl;
    }
    return 0;
}