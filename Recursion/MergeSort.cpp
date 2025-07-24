// #include<iostream>
// using namespace std;
// int merge(int *arr, int l,int r){
//     int mid=(l+r)/2;
//     int l1=mid-l+1;
//     int l2=r-mid;
//     int *first = new int[l1];
//     int *second = new int[l2];
//     int k=l;
//     for(int i=0;i<l1;i++){
//         first[i]=arr[k++];
//     }
//     for(int i=0;i<l2;i++){
//         second[i]=arr[k++];
//     }
//     int idx1=0;
//     int idx2=0;
//     k=l;
//     while(idx1<l1 && idx2<l2){ 
//         if(first[idx1]<second[idx2]){
//             arr[k]=first[idx1++];
//         }
//         else{
//             arr[k]=second[idx2++];
//         }
//     }
//     while(idx1<l1){
//         arr[k++]=first[idx1++];
//     }
//     while(idx2<l2){
//         arr[k++]=second[idx2++];
//     }
//     delete[] first;
//     delete[] second;
// }

// void mergeSort(int *arr,int l,int r){
//     if(l>=r){
//         return;
//     }
//     int mid=(l+r)/2;
//     mergeSort(arr,l,mid);
//     mergeSort(arr,mid+1,r);
//     merge(arr,l,r);
// }
// int main() {
//     int n;
//     cout<<"Enter number of elements: ";
//     cin>>n;
//     int *arr=new int[n];
//     cout<<"Enter elements: ";
//     for(int i=0;i<n;i++) {
//         cin>>arr[i];
//     }
//     mergeSort(arr,0,n-1);
//     cout<<"Sorted array: ";
//     for(int i=0;i<n;i++) {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     delete[] arr;
// }

#include <iostream>
using namespace std;
void merge(int *arr, int l, int mid, int r) {
    int l1 = mid - l + 1;
    int l2 = r - mid;
    int *first = new int[l1];
    int *second = new int[l2];
    for (int i = 0; i < l1; i++) {
        first[i] = arr[l + i];
    }
    for (int i = 0; i < l2; i++) {
        second[i] = arr[mid + 1 + i];
    }
    int idx1 = 0, idx2 = 0, k = l;
    while (idx1 < l1 && idx2 < l2) {
        if (first[idx1] < second[idx2]) {
            arr[k++] = first[idx1++];
        } else {
            arr[k++] = second[idx2++];
        }
    }
    while (idx1 < l1) {
        arr[k++] = first[idx1++];
    }
    while (idx2 < l2) {
        arr[k++] = second[idx2++];
    }
    delete[] first;
    delete[] second;
}
void mergeSort(int *arr, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
    return 0;
}

//Time Complexity O(nlogn),Space Complexity O(n).

// #include <iostream>
// #include <vector>

// using namespace std;

// // Function to merge two halves and count inversions
// int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
//     int i = left;
//     int j = mid + 1;
//     int k = 0;
//     int inversions = 0;

//     vector<int> temp(right - left + 1);
//     while (i <= mid && j <= right) {
//         if (arr[i] <= arr[j]) {
//             temp[k++] = arr[i++];
//         } else {
//             // There are mid - i inversions, because all the remaining elements
//             // in the left subarray (arr[i] to arr[mid]) are greater than arr[j]
//             inversions += (mid - i + 1);
//             temp[k++] = arr[j++];
//         }
//     }
//     while (i <= mid) {
//         temp[k++] = arr[i++];
//     }
//     while (j <= right) {
//         temp[k++] = arr[j++];
//     }
//     for (int m = 0; m < temp.size(); m++) {
//         arr[left + m] = temp[m];
//     }

//     return inversions;
// }
// int mergeSortAndCount(vector<int>& arr, int left, int right) {
//     int inversions = 0;
//     if (left < right) {
//         int mid = left + (right - left) / 2;

//         inversions += mergeSortAndCount(arr, left, mid);
//         inversions += mergeSortAndCount(arr, mid + 1, right);
//         inversions += mergeAndCount(arr, left, mid, right);
//     }
//     return inversions;
// }
// int main() {
//     vector<int> arr = {1, 20, 6, 4, 5};
//     int n = arr.size();
//     int inversionCount = mergeSortAndCount(arr, 0, n - 1);
//     cout << "Number of inversions: " << inversionCount << endl;
//     return 0;
// }