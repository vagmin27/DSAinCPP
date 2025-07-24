#include<bits/stdc++.h>
using namespace std;
bool isPresent(int arr[][4], int t, int r , int c){
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            if(arr[r][c]==t){
                return true;
            }
        }
    }
    return false;
}
//To print row-wise sum
void rowSum(int arr[][4],int row, int col){
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<4;j++){
            sum+=arr[i][j];
        }
        cout<<sum<<" ";
    }
}
int largestRowSum(int arr[][4], int r, int c){
    int mx=INT_MIN;
    int n=-1;
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<4;j++){
            sum+=arr[i][j];
        }
        if(sum>mx){
            mx=sum;
            n=r;
        }
    }
    cout<<"Max sum is: "<<mx<<endl;
    return r;
}
int main(){
    int arr[3][4];
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    int target;
    cout<<"Enter target element : ";
    cin>>target;
    if(isPresent(arr,target,3,4)){
        cout<<"Element found"<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
    rowSum(arr,3,4);
    largestRowSum(arr,3,4);
}