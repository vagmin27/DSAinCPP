// #include <iostream>
// using namespace std;

// int main() {
// 	int n;
//     cout<<"Enter a number: ";
//     cin>>n;
// 	int count = 0;
// 	// Count the number of integers divisible by 2
// 	for(int i = 2; i < n; i += 2) {
// 		count++;
// 	}
// 	// Count the number of integers divisible by 3
// 	for(int i = 3; i < n; i += 3) {
// 		count++;
// 	}
// 	// Count the number of integers divisible by 5
// 	for(int i = 5; i < n; i += 5) {
// 		count++;
// 	}
// 	// Count the number of integers divisible by both 2 and 3
// 	for(int i = 6; i < n; i += 6) {
// 		count--;
// 	}
// 	// Count the number of integers divisible by both 2 and 5
// 	for(int i = 10; i < n; i += 10) {
// 		count--;
// 	}
// 	// Count the number of integers divisible by both 3 and 5
// 	for(int i = 15; i < n; i += 15) {
// 		count--;
// 	}
// 	// Count the number of integers divisible by 2, 3, and 5
// 	for(int i = 30; i < n; i += 30) {
// 		count++;
// 	}
// 	// Print the final count
// 	cout << "The number of positive integers less than " << n << " that are divisible by either 2, 3, or 5 is " << count << "." << endl;
// }
#include <iostream>
#include <set>
using namespace std;
int main() {
    set<int> A = {1, 2, 3, 4};
    set<int> B = {3, 4, 5, 6};
    set<int> C = {5, 6, 7, 8};

    // Calculate sizes of each set
    int sizeA = A.size();
    int sizeB = B.size();
    int sizeC = C.size();

    // Calculate intersections
    set<int> AB, AC, BC, ABC;

    for (int a : A) {
        if (B.count(a)) AB.insert(a);
        if (C.count(a)) AC.insert(a);
    }
    
    for (int b : B) {
        if (C.count(b)) BC.insert(b);
    }

    // ABC is the intersection of all three sets
    for (int c : C) {
        if (A.count(c) && B.count(c)) ABC.insert(c);
    }

    // Applying inclusion-exclusion principle
    int unionSize = sizeA + sizeB + sizeC
                    - AB.size() - AC.size() - BC.size()
                    + ABC.size();

    cout << "Size of A ∪ B ∪ C: " << unionSize << endl;

    return 0;
}
