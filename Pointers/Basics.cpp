#include<iostream>
using namespace std;
int main(){
    int num=5;
    cout<<"Value is: "<<num<<endl;
    //Address of Operator(&)
    cout<<"Address of num is: "<<&num<<endl;
    int *ptr=&num;
    cout<<"Address is: "<<ptr<<endl;
    cout<<"Value is: "<<*ptr<<endl;
    double d=4.3;
    double *p2=&d;
    cout<<"Address is: "<<p2<<endl;
    cout<<"Value is: "<<*p2<<endl;
    cout<<"size of integer is: "<<sizeof(num)<<endl;
    cout<<"size of double is: "<<sizeof(d)<<endl;
    cout<<"size of pointer is: "<<sizeof(ptr)<<endl;
    cout<<"size of pointer2 is: "<<sizeof(p2)<<endl;
}