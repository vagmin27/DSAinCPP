#include <iostream>
using namespace std;
int main(){
    int n=5;
    for(int j=1;j<=n;j++){
        int s=n-j;
        for(int m=0;m<s;m++){
            cout<<" ";
        }
        int l=2*j-1;
        for(int k=0;k<l;k++){
        cout<<char('A'+k);
        }
        cout<<endl;
    }
    for(int j=n+1;j<2*n-1;j++){
        int s=j-n;
        for(int m=0;m<s;m++){
            cout<<" ";
        }
        int l=2*(2*j)-1;
        for(int k=0;k<l;k++){
        cout<<char('A'+k);
    }
    cout<<endl;
    }
}