#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;++i) {
            cin>>v[i];
        }
        int s=v[n-1];
        int pos=n-1;
        for (int i=n-2;i>=0;--i) {
            if (v[i]<=s/2) {
                pos--;
            }
            else {
                break;
            }
        }
        cout<<pos+1<<endl;
    }
    return 0;
}