//Example a=2;
// #include <iostream>
// using namespace std;
// int TwoPower(int n){
//     if(n==0) return 1;
//     else{
//         return 2*TwoPower(n-1); //Recursive Multiplication
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     int pow = TwoPower(n);
//     cout<<pow<<endl;
// }

//General Case
//Optimized Approach
//Time:O(n),Space:O(n)
#include<iostream>
using namespace std;
double Power(int a, int n){
    if(n==0) return 1;
    if(n==1) return a;
    int ans=Power(a,n/2);
    if(n%2==0) return ans*ans;
    else if(n%2==1) return a*ans*ans;
    else return 1/Power(a,-n);
}

int main(){
    double a,n;
    cout<<"Enter the base number: ";
    cin>>a;
    cout<<"Enter the power: ";
    cin>>n;
    double ans=Power(a,n);
    cout<<"Answer is "<<ans<<endl;
}