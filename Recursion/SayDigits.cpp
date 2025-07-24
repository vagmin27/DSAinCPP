// #include <iostream>
// using namespace std;
// void sayDigit(int n, string arr[]) {
//     if (n == 0) return;
//     int digit=n%10;
//     n=n/10;
//     sayDigit(n,arr);
//     if(n==0){
//         cout<<arr[digit]<<" ";//Single digited numbers
//     }
//     else if(n==1){
//         cout<<arr[10+digit]<<" ";//(10-19)
//     }
//     else{
//         if(n%10==0){
//             cout<<arr[18+n/10]<<" ";//(20,30,40,50,60,70,80,90)
//         }
//         else{
//             cout<<arr[18+n/10]<<" "<<arr[digit]<<" ";//Twenty One etc
//         }
//     }
// }

// int main() {
//     string arr[] = {
//         "Zero", "One", "Two", "Three", "Four","Five", "Six", "Seven", "Eight", "Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninty","Hundred","Thousand","Million","Billion"
//     };
//     int n;
//     cout << "Enter a number: ";
//     cin >> n;
//     if(n<0){
//         cout<<"Minus ";
//         n=-n;//Handles negative
//     }
//     if (n==0) {
//         cout << arr[0] << endl; // Special case for 0
//     } else {
//         sayDigit(n, arr); // Call the function to print the digits
//         cout << endl;
//     }
//     return 0;
// }

//LeetCode Problem No 273(Integer to English Words)(Hard)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //globally declare arrays
    string ones[20] = {
        "", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight",
        " Nine", " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen",
        " Seventeen", " Eighteen", " Nineteen"
    };
    string tens[10] = {
        "", " Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", 
        " Eighty", " Ninety"
    };
    string thousands[4] = {
        "", " Thousand", " Million", " Billion"
    };
    string helper(int n) {
        if (n < 20) 
            return ones[n];
        if (n < 100) 
            return tens[n / 10] + helper(n % 10);
        if (n < 1000) 
            return helper(n / 100) + " Hundred" + helper(n % 100);
        for (int i = 3; i >= 0; i--) {
            if (n >= pow(1000, i)) {
                return helper(n / pow(1000, i)) + thousands[i] + helper(n % (int)pow(1000, i));
            }
        }
        return "";
    }
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        return helper(num).substr(1);
    }
};

int main(){
    Solution s;
    int num;
    cout << "Enter the number : ";
    cin>>num;
    cout<<endl;
    cout << "Number in words is : "<<s.numberToWords(num)<<endl;
}