#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        long r = 0;
        while (x) {
            r=(r*10)+(x%10);
            x=x/10;
        }
        if (r>INT_MAX||r<INT_MIN) {
            return 0;
        }
        return int(r);
    }
};
int main(){
    Solution s;
    int x;
    cin>>x;
    cout<<s.reverse(x)<<endl;
}