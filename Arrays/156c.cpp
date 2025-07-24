#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n,k;
	    vector<int> v(n);
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    sort(v.begin(),v.end());
        int mx=-1;
	    for(int i=0;i<n-k;i++){
	        int mn1=v[0];
            int mx1=v[i-1];
            int mn2=v[i];
            int mx2=v[n-1];
            int s=mx1+mx2+mn1+mn2;
            mx=max(mx,s);
	    }
	    cout<<mx<<endl;
	}
}