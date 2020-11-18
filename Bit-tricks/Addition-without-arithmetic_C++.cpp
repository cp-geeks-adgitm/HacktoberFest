#include<bits/stdc++.h>
using namespace std;

int main()
{
    int first, second;
    cout<<"Enter first number: \n"; cin>>first;
    cout<<"Enter second number: \n"; cin>>second;
    while(second != 0)
    {
        int carry = first & second;

        first = first ^ second;

        second = carry << 1;
    }
    cout<<"Sum of first and second is: "<<first<<"\n";
}