#include <iostream>
using namespace std;
bool isSorted(int *arr, int size){
    if(size==0 || size==1) return true;
    if(arr[0]>arr[1]) return false;
    else{
        bool r= isSorted(arr+1,size-1);
        return r;
    }
}
int main(){
    int n;
    cout<<"Enter the length of Array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the Array elements : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool ans=isSorted(arr,n);
    if(ans){
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;
    }
}