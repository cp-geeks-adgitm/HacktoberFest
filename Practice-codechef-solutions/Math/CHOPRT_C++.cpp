#include <iostream>
using namespace std;

int main() {
	unsigned t;
	cin>>t;
	while(t--){
	    unsigned long long a,b;
	    cin>>a>>b;
	    if(a>b)
	    cout<<">"<<endl;
	    else if(a<b)
	    cout<<"<"<<endl;
	    else
	    cout<<"="<<endl;
	}
	return 0;
}
