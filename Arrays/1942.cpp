#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int t) {
        int x= times[t][0];
        int n= times.size();
        sort(times.begin(),times.end());
        int h=0;
        for(int i=0;i<n;i++){
            if(times[i][0]==x){
                h=i;
                break;
            }
        }
        for(int i=0;i<h;i++){
           for(int j=0;j<=i;j++){
                if(times[i+1][0]>=times[j][1]){
                    times[j][0]=times[i+1][0] ;
                    times[j][1]=times[i+1][1] ;
                    times[i+1][0]=-1;
                    times[i+1][1]=-1;
                    break;
                }
            }
        }
        int g=0;
        for(int i=0;i<=h;i++){
            if(x==times[i][0]){
                g=i;
                break;
            }
        }
        return g;     
    }  
};
int main(){
    Solution s;
    vector<vector<int>> times={{1,4},{2,3},{4,6}};
    int t=1;
    cout<<s.smallestChair(times,t);
}