#include<iostream>
using namespace std;
void InsertionSort(int *arr,int n){
    if(n==1||n==0) return;
    InsertionSort(arr,n-1);
    int key = arr[n-1];
    int j=n-2;
    while(j>=0 && arr[j]>key){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
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
    InsertionSort(arr, n);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}