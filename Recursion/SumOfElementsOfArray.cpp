#include<iostream>
#include<vector>
using namespace std;
int Sum(int n,int arr[]){
    if(n==0) return 0;
    if(n==1) return arr[0];
    else return arr[n-1]+Sum(n-1,arr);
}

int main(){
    int n;
    cout<<"Enter the size of Array : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements of Array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=Sum(n,arr.data());
    cout<<"Sum of elements of Array : "<<sum<<endl;
}