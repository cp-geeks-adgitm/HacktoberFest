#include<bits/stdc++.h>
using namespace std;

int main()
{   
    int first, second;
    cout<<"Enter first number: \n"; cin>>first;
    cout<<"Enter second number: \n"; cin>>second;

    first = first ^ second;
    second = first ^ second;
    first = first ^ second;

    cout<<"Swapped variables: "<<first<<" "<<second;
}