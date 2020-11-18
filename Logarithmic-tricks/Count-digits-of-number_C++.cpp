#include<bits/stdc++.h>
using namespace std;

#define llu long long unsigned

//Function to count digits of number entered by user
llu countDigitsOfNumber(llu n){
    return floor(log10(n) + 1);
}

//main function
int main()
{
    llu n;
    cout<<"Enter number: \n";
    cin>>n;
    cout<<countDigitsOfNumber(n);
}