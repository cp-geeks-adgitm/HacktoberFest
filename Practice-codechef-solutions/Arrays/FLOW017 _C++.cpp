#include<bits/stdc++.h>
using namespace std;

int main() {
	unsigned long long t;
	cin>>t;
	while(t--)
	{
	    unsigned long long a[3];
	    for(int i=0;i<3;i++)
	    cin>>a[i];
	    sort(a,a+3);
	    cout<<a[1]<<endl;
	    
	}// your code goes here
	return 0;
}