#include<iostream>
using namespace std;
bool binarySearch(int *arr,int s,int e,int k){
    if(s>e) return false;
    int mid=(s+e)/2;
    if(arr[mid]==k) return true;
    else if(arr[mid]>k) return binarySearch(arr,s,mid-1,k);
    else return binarySearch(arr,mid+1,e,k);
}
int main(){
    // int size=6;
    int arr[6]={1,2,3,4,5,6};
    int key=2;
    bool found = binarySearch(arr,0,6,key);
    if(found){
        cout<<"Element found"<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
}