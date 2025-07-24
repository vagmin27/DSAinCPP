#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        if(bits[n-1]==1) return false;
        int i=0;
        while(i<n) {
            if(bits[i]==0) i++;
            else if(bits[i]==1) {
                i+=2;
                if(i==n) return false;
            }
        }
        return true;
    }
};
int main() {
    Solution s;
    vector<int> bits = {1, 0, 0};
    bool result=s.isOneBitCharacter(bits);
    if (result) {
        cout<<"true"<<endl;
    } else {
        cout<<"false"<<endl;
    }
}