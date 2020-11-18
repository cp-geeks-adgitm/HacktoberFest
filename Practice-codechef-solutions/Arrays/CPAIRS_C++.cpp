#include <iostream>
using namespace std;

int main() {
	long int n,t;
	cin>>n;
	while(n--)
	{  int total=0,count=0;
	   cin>>t;
	   int a[t];
	   for(int i=0;i<t;i++)
	   cin>>a[i];
	   for(int i=0;i<t;i++)
	   {
	   if(a[i]%2==0)
	   total++;
	   else
	   count=count+total;
	   }
	   cout<<count<<endl;
	}// your code goes here
	return 0;
}