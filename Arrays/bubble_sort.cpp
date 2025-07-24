#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &v) {
    int n = v.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;  // No swaps means the array is sorted
        }
    }
}
// The bubbleSort function sorts a vector of integers using the bubble sort 
// algorithm with an optimization. It iteratively compares adjacent elements
//  and swaps them if they are out of order. Each pass through the vector places
//  the largest unsorted element in its correct position. The optimization 
// involves a swapped flag to detect if any elements were swapped during a pass.
//  If no elements are swapped, the function terminates early, as the vector is already sorted.
//  This reduces unnecessary comparisons and improves performance for partially sorted lists.
//  The function operates in O(n²) time complexity in the worst case.
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    bubbleSort(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}