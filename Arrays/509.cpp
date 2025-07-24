#include<iostream>
#include <vector>
using namespace std;
int fib(int n) {
    if(n==0) return 0;
    if(n==1) return 1;
    vector<int> a(n+1);
    a[0]=0;
    a[1]=1;
    for(int i=2;i<=n;i++){
        a[i]=a[i-1]+a[i-2];
    }
    return a[n];
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int ans=fib(n);
    cout<<"Fibonacci number of "<<n<<" is :"<<ans<<endl;
}