#include <iostream>
using namespace std;
int partition(int arr[], int s, int e) {
    int p = arr[s]; 
    int c = 0;
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] < p) {
            c++;
        }
    }
    int pivotIdx = s + c;
    swap(arr[pivotIdx], arr[s]);
    int i = s, j = e;
    while (i < pivotIdx && j > pivotIdx) {
        while (i < pivotIdx && arr[i] < p) {
            i++;
        }
        while (j > pivotIdx && arr[j] > p) {
            j--;
        }
        if (i < pivotIdx && j > pivotIdx) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIdx; 
}
void quickSort(int arr[], int s, int e) {
    if (s >= e) return; 
    int p = partition(arr, s, e);
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e); 
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}