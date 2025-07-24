#include<iostream>
using namespace std;
bool linearSearch(int arr[],int size,int k){
    if(size==0) return false;
    if(arr[0]==k){
        return true;
    }
    else{
        bool rem=linearSearch(arr+1,size-1,k);
        return rem;
    }
}
int main(){
    int size;
    cout<<"Enter the length of Array : ";
    cin>>size;
    int arr[size];
    cout<<"Enter the Array elements : "<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the key element : ";
    cin>>key;
    if(key>size){
        cout<<"Error"<<endl;
    }
    bool found = linearSearch(arr,size,key);
    if(found){
        cout<<"Element found"<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
}