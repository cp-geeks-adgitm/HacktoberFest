//This program is to check if a number is power of 2 or not
//Example: 8, 16, 32 are true but 9, 15, 21 are not

#include<bits/stdc++.h>
using namespace std;

#define llu long long unsigned

//Function to check if a number is power of two or not
bool numberIsPowerOfTwo(llu n){
    return (ceil(log2(n)) == floor(log2(n)));
}

//main function
int main()
{   
    cout<<"Enter number: \n";
    llu n;
    cin>>n;
    if(numberIsPowerOfTwo(n))
        cout<<"YES\n";
    else
        cout<<"NO\n";
}