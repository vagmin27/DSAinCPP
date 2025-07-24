#include<bits/stdc++.h>
using namespace std;
double func(double x){
    return (x*x*x)-(2*x*x)+3;
}
double c;
void bisection(double a,double b){
    if(func(a)*func(b)>= 0){
    cout<<"Incorrect a and b";
        return;
    }
    c=a;
    while ((b-a)>=0.01){
        c=(a+b)/2;
        if (func(c)==0.0){
            break;
        }
        else if(func(c)*func(a)<0){
            b=c;
        }
        else{
        a=c;
        }
    }
}
int main(){
    double a,b;
    cin>>a>>b;
    bisection(a,b);
    cout<<endl;
    cout<<"The value of root is = "<<c<<endl;
}