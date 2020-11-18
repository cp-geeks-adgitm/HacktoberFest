#include <iostream>
using namespace std;

int main() {
    unsigned long long t,n;
    cin>>t;
    while(t--)
    {   
        unsigned long long p=1;
        cin>>n;
        for(int i=1;i<=n;i++)
        p=p*i;
        cout<<p<<endl;
    }
	// your code goes here
	return 0;
}