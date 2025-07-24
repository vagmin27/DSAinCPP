#include <iostream>
using namespace std;
int fact(int n){
    if(n==0) return 1;
    else{
        return n*fact(n-1);  //Recursive call
    }
}
int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    int ans=fact(n);
    cout<<"Factorial of the number is : "<<ans<<endl;
}