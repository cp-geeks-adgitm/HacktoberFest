#include <iostream>
using namespace std;


int main() {
	int t,n,k;
	cin>>t;
	while(t--)
	{
	    int c=0;
	    cin>>n>>k;
	    int a[n];
	    for(int i=0;i<n;i++)
        {
           cin>>a[i]; 
           if(a[i]>k)
           {
               i=i-1;
               n=n-1;
           }
           
        }
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=i+1;j<n;j++)
	        {
	            if(a[i]+a[j]==k)
                {
                    c=1;
                    break;
                }
	           
	        }
	        if(c==1)
	        break;
	    }
	    if(c==0)
	    cout<<"No"<<endl;
	    else
	    cout<<"Yes"<<endl;
	}// your code goes here
	return 0;
}