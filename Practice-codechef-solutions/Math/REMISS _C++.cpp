#include <iostream>
using namespace std;

int main() {
	unsigned long long t;
	cin>>t;
	while(t--){
	    unsigned long long a,b;
	    cin>>a>>b;
	    if(a>b)
	    cout<<a<<" "<<a+b<<endl;
	    else
	    cout<<b<<" "<<a+b<<endl;
	    
	}
	return 0;
}
