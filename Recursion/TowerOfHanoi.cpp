#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char from, char to,char img){
    if (n == 0) {
        return;
    }
    towerOfHanoi(n-1,from,img,to);
    cout<<"Move disk "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
    towerOfHanoi(n-1,img,to,from);
}
int main(){
    int N;
    cout<<"Enter number of disks to be moved : "<<endl;
    cin>>N;
    towerOfHanoi(N, 'A', 'C', 'B');
    return 0;
}