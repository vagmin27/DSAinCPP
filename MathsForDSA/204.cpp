#include<bits/stdc++.h>
using namespace std;
// bool isPrime(int n){
//     if(n<=1) return false;
//     for(int i=0;i<n;i++){
//         if(n%i==0) return false;
//     }
//     return true;
// }
// int countPrimes(int n){
//     int c=0;
//     for(int i=0;i<n;i++){
//         if(isPrime(i)) c++;
//     }
//     return c;
// }
// ***Sieve Of Eratosthenes***
// int countPrimes(int n){
//     if (n < 2) return 0;
//     vector<bool> prime(n+1,true);
//     prime[0]=prime[1]=false;
//     int c=0;
//     for(int i=2;i*i<n;i++){
//         if(prime[i]){
//             for(int j=i*i;j<n;j=j+1){
//                 prime[j]=false;
//             }
//         }
//     }
//     for(bool i:prime) {
//         if(i) c++;
//     }
//     return c;
// }
int countPrimes(int n){
    int c=0;
    vector<bool> prime(n+1,true);
    prime[0]=prime[1]=false;
    for(int i=2;i<n;i++){
        if(prime[i]){
            c++;
            for(int j=2*i;j<n;j+=i){
                prime[j]=0;
            }
        }
    }
    return c;
}
int main(){
    int n;
    cin>>n;
    cout<<countPrimes(n)<<endl;
}