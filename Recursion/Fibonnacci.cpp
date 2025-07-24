#include <iostream>
using namespace std;
// int Fibo(int n){
//     if(n==0) return 0;
//     if(n==1) return 1;
//     int ans=Fibo(n-1)+Fibo(n-2);
//     return ans;
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<Fibo(n);
// }
//Better Run-Time
int fib(int n) {
    int prev1 = 1;
    int prev2 = 0;
    if(n == 0){
        return prev2;
    }
    for(int i = 2;i<=n;i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int main(){
    int n;
    cin>>n;
    cout<<fib(n);
}