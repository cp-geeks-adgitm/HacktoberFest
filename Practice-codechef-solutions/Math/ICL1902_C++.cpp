#include <iostream>
#include<math.h>
using namespace std;

int main() {
int t,d;
    cin>>t;
    while(t--)
    {   int c=0;
        int n;
        cin>>n;
        while(n)
        {
          d=sqrt(n);
          c++;
          n=n-d*d;
        }
        cout<<c<<endl;
    }	// your code goes here
	return 0;
}
