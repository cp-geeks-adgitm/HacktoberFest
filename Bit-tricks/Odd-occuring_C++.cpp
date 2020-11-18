//Program to find number whose frequency is odd 

#include<bits/stdc++.h>
using namespace std;

#define fo(i, n) for(int i=0; i<n; i++)

int main()
{
    cout<<"Enter array size: \n";
    int n, result = 0; cin>>n;
    int arr[n];
    
    cout<<"Enter array elements: \n";
    fo(i, n)
        cin>>arr[i];
    fo(i ,n)
        result ^= arr[i];
    
    if(result == 0)
        cout<<"Every number has even frequency. \n";
    else
        cout<<result<<" has appeared odd number of times. \n";
}