#include <iostream>
using namespace std;

int main() {
	unsigned long long t,w;
    cin>>t;
    int a[t],b[t],c[t],l,s1=0,s2=0;
    for(int i=0;i<t;i++)
    {   
        cin>>a[i]>>b[i];
        s1=s1+a[i];
        s2=s2+b[i];
        if(s1>s2)
        {
            c[i]=s1-s2;
        }
        if(s2>s1)
        {
            c[i]=s2-s1;
        }
    }
    
        for(int i=0;i<t;i++)
        {
            l=c[i];
        for(int j=0;j<t;j++)
        {   
            if(l<c[j])
            l=c[j];
        }
        }
        for(int i=0;i<t;i++)
        {   
            if(c[i]==l)
             {
                 if(a[i]>b[i])
                 w=1;
                 else
                 w=2;
             }
        }
        cout<<w<<" "<<l;
	// your code goes here
	return 0;
}
