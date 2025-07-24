#include <iostream>
using namespace std;
void SelectionSort(int *arr, int n, int idx = 0) {
    if (idx == n-1) return;
    int min = idx;
    for (int j = idx + 1; j < n; j++) {
        if (arr[j] < arr[min]) {
            min = j;
        }
    }
    swap(arr[idx], arr[min]);
    SelectionSort(arr,n,idx+1);
}

int main() {
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    SelectionSort(arr, n);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}